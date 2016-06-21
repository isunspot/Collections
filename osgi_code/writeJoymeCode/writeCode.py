#!/usr/bin/python
# -*- coding:utf-8 -*-

import os
import sys
import json

current_path = sys.path[0]
json_file = current_path + '/package_class_interface.json'
root = current_path + '/joyme_cmcc'

def get_json_obj():
    with open(json_file) as fp:
        json_obj = json.loads(fp.read())
    fp.close()
    return json_obj

def write_joyme_h(json_obj):
    file_path = current_path + "/joyme_cmcc.h"
    with open(file_path, 'w') as fp:
        print "Writing: " + file_path
        fp.write("""#ifndef _JOYME_CMCC_H_
#define _JOYME_CMCC_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/msg.h>
#include <sys/uio.h>
#include "json.h"
#include "joyme.h"
#include "libtcapi.h"
#include "json_helper.h"
\n""")
        for package_name in json_obj:
            if not package_name == 'comment':
                for class_name in json_obj[package_name]:
                    for interface_name in json_obj[package_name][class_name]:   # called counts 151.
                        interface_list = json_obj[package_name][class_name][interface_name]
                        fp.write("int joyme_cmcc_%s(" % interface_name)
                        if interface_list[1] == "int" or interface_list[1] == "boolean":
                            fp.write("const int*, ")
                        elif interface_list[1] == "String":
                            fp.write("const char*, ")
                        else:
                            print "Error: unknown function type --> %s" % interface_list[i]
                        parameter = interface_list[2].split(' ')
                        if len(parameter) == 1:
                            pass
                        elif len(parameter) > 1:
                            type_queue = []
                            for i in range(len(parameter)):
                                if i % 2 == 0:
                                    type_queue.append(parameter[i])
                            for i in range(len(type_queue)):
                                if type_queue[i] == "int" or type_queue[i] == "boolean":
                                    fp.write("int, ")
                                elif type_queue[i] == "String" or type_queue[i] == "BundleContext":
                                    fp.write("char*, ")
                                elif type_queue[i] == "byte[]":
                                    fp.write("void*, ")
                                elif type_queue[i] == "String[]":
                                    fp.write("char*[], int, ")
                                else:
                                    print "Error: unknown param type --> %s" % type_queue[i]
                        else:
                            print "Error: parameter analysis failed --> %s" % interface_list[2]
                        fp.seek(-2, 1)
                        fp.write(");\n")
        fp.write("\n#endif /* _JOYME_CMCC_H_ */")
    fp.close()

def write_head(fp):
        fp.write("""#include "joyme_cmcc.h"

typedef enum {
	JOYME_NONE = 0,
	JOYME_ERR,
	JOYME_INFO,
	JOYME_DEBUG,
	JOYME_ALL
} DebugLevel;

\n""")

def write_fucntion(fp, interface_name, interface_list):
    fp.write("int joyme_cmcc_%s(" % interface_name)
    if interface_list[1] == "int" or interface_list[1] == "boolean":
        fp.write("const int* response, ")
    elif interface_list[1] == "String":
        fp.write("const char* response, ")
    else:
        print "Error: unknown function type --> %s" % interface_list[i]
    parameter = interface_list[2].split(' ')
    if len(parameter) == 1:
        pass
    elif len(parameter) > 1:
        type_queue = []
        name_queue = []
        for i in range(len(parameter)):
            if i % 2 == 0:
                type_queue.append(parameter[i])
            else:
                name_queue.append(parameter[i])
        for i in range(len(type_queue)):
            if name_queue[i][-1] == ',':
                name = name_queue[i][:-1]
            else:
                name = name_queue[i]
            if type_queue[i] == "int" or type_queue[i] == "boolean":
                fp.write("int %s, " % name)
            elif type_queue[i] == "String" or type_queue[i] == "BundleContext":
                fp.write("char* %sStr, " % name)
            elif type_queue[i] == "byte[]":
                fp.write("void* %sByte, " % name)
            elif type_queue[i] == "String[]":
                fp.write("char*%sList[], int %sNum, " % (name, name))
            else:
                print "Error: unknown param type --> %s" % type_queue[i]
    else:
        print "Error: parameter analysis failed --> %s" % interface_list[2]
    fp.seek(-2, 1)
    fp.write(")\n")

def write_context(fp, interface_name):
    fp.write("""{
    int ret = 0;

    joyme_printf(JOYME_INFO, "joy_cmcc_%s: enter============>\\n");


    // please erasure this line and write someting.


    joyme_printf(JOYME_INFO, "joy_cmcc_%s: leave============>\\n");

    return ret;
}
""" % (interface_name, interface_name))

def write_code(package_name, class_name, interface_name, interface_list):
    file_path = "%s/joyme_cmcc_%s.c" % (root, interface_name)
    with open(file_path, 'w') as fp:
        print "Writing: " + file_path
        write_head(fp)
        write_fucntion(fp, interface_name, interface_list)
        write_context(fp, interface_name)
    fp.close()

def write_joyme_code(json_obj):
    for package_name in json_obj:
        if not package_name == 'comment':
            for class_name in json_obj[package_name]:
                for interface_name in json_obj[package_name][class_name]:
                    write_code(package_name, class_name, interface_name, json_obj[package_name][class_name][interface_name])    # called counts 151.

if __name__ == '__main__':
    json_obj = get_json_obj()
    write_joyme_h(json_obj)
    write_joyme_code(json_obj)













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
