#!/usr/bin/python
# -*- coding:utf-8 -*-

import os
import json

root = 'object/'

def read_from_file(file):
    fp = open(file)
    context = fp.read()
    fp.close()
    return context

def make_dir(dir):
    full_dir = root + dir
    if (not os.path.exists(full_dir)):
        os.mkdir(full_dir)
        print "mkdir for %s" % full_dir

def make_file(package_name, class_name):
    path = root + package_name + '/' + class_name + '.java'
    path_imp = root + package_name + '/' + class_name + 'Imp.java'
    if (not os.path.exists(path)):
        fp = open(path, 'w')
        fp.close()
        print "touch for %s" % path
    if (not os.path.exists(path_imp)):
        fp = open(path_imp, 'w')
        fp.close()
        print "touch for %s" % path_imp

def write_java_def_code(json_obj, file_def, package_name, class_name):
    fp = open(file_def, 'w')
    try:
        fp.write("package com.chinamobile.smartgateway.%s;\n\n" % package_name)
        fp.write("import org.osgi.framework.BundleContext;\n\n")
        fp.write("public interface %s {\n" % class_name)
        for interface_name in json_obj[package_name][class_name]:
            line = json_obj[package_name][class_name][interface_name][0]
            fp.write("\t%s\n" % line)
        fp.write("}\n")
    except IOError:
        print "Fail: write %s error" % file_def
    finally:
        fp.close()

def get_pure_value(param):
    raw_param = param.split(' ')
    ripe_param = ''
    for i in range(len(raw_param)):
        if i % 2 == 1:
            ripe_param += raw_param[i]
            ripe_param += ' '
    # print "------> [%s]" % ripe_param[:-1]
    return ripe_param[:-1]

def write_java_imp_code(json_obj, file_imp, package_name, class_name):
    fp = open(file_imp, 'w')
    try:
        fp.write("package com.chinamobile.smartgateway.%s;\n\n" % package_name)
        fp.write("import org.osgi.framework.BundleContext;\n\n")
        fp.write("public class %sImp implements %s {\n\n" % (class_name, class_name))
        fp.write("""    static{
		System.loadLibrary("bundle");
	}\n\n""")
        for interface_name in json_obj[package_name][class_name]:
            return_type = json_obj[package_name][class_name][interface_name][1]
            param_value = json_obj[package_name][class_name][interface_name][2]
            line = "public native %s %sJni(%s);" % (return_type, interface_name, param_value)
            fp.write("\t%s\n" % line)
        fp.write("\n")

        for interface_name in json_obj[package_name][class_name]:
            return_type = json_obj[package_name][class_name][interface_name][1]
            param_value = json_obj[package_name][class_name][interface_name][2]
            param_pure_value = get_pure_value(param_value)
            lines ="""\tpublic %s %s(%s){
        return %sJni(%s);
    }\n""" % (return_type, interface_name, param_value, interface_name, param_pure_value)
            fp.write(lines)
        fp.write("}\n")
    except IOError:
        print "Fail: write %s error" % file_imp
    finally:
        fp.close()

def write_java_code(json_obj, package_name, class_name):
    file_def = root + package_name + '/' + class_name + '.java'
    file_imp = root + package_name + '/' + class_name + 'Imp.java'
    if (os.path.exists(file_def)):
        write_java_def_code(json_obj, file_def, package_name, class_name)
    else:
        print "Fail: file %s not exist" % file_def
    if (os.path.exists(file_imp)):
        write_java_imp_code(json_obj, file_imp, package_name, class_name)
    else:
        print "Fail: file %s not exist" % file_def

# 深度优先遍历json树
def write_code(json_obj):
    # package
    for package_name in json_obj:
        if not package_name == 'comment':
        # if package_name == 'accessservices':    # 单pacakge debug
            make_dir(package_name)
            # class
            for class_name in json_obj[package_name]:
                make_file(package_name, class_name)
                # if class_name == 'AccessInfoQueryService':  #单class debug
                write_java_code(json_obj, package_name, class_name)

# 深度优先遍历json树
def write_activator(json_obj):
    fp = open("activator.txt", "w")
    try:
        # package
        for package_name in json_obj:
            if not package_name == 'comment':
                # class
                for class_name in json_obj[package_name]:
                    fp.write("context.registerService(%s.class.getName(), new %sImp(), null);\n" % (class_name, class_name))
    except IOError:
        print  "Fail: write activator.txt error"
    finally:
        fp.close()


if __name__ == '__main__':
    file = "../sourceFile/package_class_interface.json"
    if (not os.path.exists("object")):
        os.mkdir("object")
    context = read_from_file(file)
    json_obj = json.loads(context)
    write_code(json_obj)
    write_activator(json_obj)
