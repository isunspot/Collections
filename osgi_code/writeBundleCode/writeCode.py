#!/usr/bin/python
# -*- coding:utf-8 -*-

import os
import sys
import json

json_file = sys.path[0] + '/package_class_interface.json'
root = sys.path[0] + '/cmcc_source'

def get_json_obj():
    with open(json_file) as fp:
        json_obj = json.loads(fp.read())
    fp.close()
    return json_obj

def write_head(fp):
    fp.write("""#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jni.h"
#include "joyme.h"
#include "joyme_cmcc.h"
#include "cmcc_include.h"

typedef enum {
	JOYME_NONE = 0,
	JOYME_ERR,
	JOYME_INFO,
	JOYME_DEBUG,
	JOYME_ALL
} DebugLevel;

""")

def write_function_name(fp, interface_list):
    index = fp.name.rindex('/') + 1
    function_name = fp.name[index:-2]
    if interface_list[1] == "String":
        return_type = "jstring"
    elif interface_list[1] == "int":
        return_type = "jint"
    elif interface_list[1] == "boolean":
        return_type = "jboolean"
    else:
        print "Error: unknown return type --> %s" % interface_list[1]
    fp.write("JNIEXPORT %s JNICALL %s\n" % (return_type, function_name))

def write_function_param(fp, interface_list):
    type_queue = []
    name_queue = []
    parameter = interface_list[2].split(' ')
    if len(parameter) == 1:
        fp.write("(JNIEnv *env, jobject obj)\n")
    elif len(parameter) > 1:
        for i in range(len(parameter)):
            if i % 2 == 0:
                type_queue.append(parameter[i])
            else:
                name_queue.append(parameter[i])
        if len(type_queue) != len(name_queue):
            print "Error: parameter analysis fail --> %s" % interface_list[2]

        fp.write("(JNIEnv *env, jobject obj, ")
        for i in range(len(type_queue)):
            if type_queue[i] == "int":
                fp.write("%s " % "jint")
            elif  type_queue[i] == "boolean":
                fp.write("%s " % "jboolean")
            elif  type_queue[i] == "String" or type_queue[i] == "BundleContext":
                fp.write("%s " % "jstring")
            elif type_queue[i] == "String[]":
                fp.write("%s " % "jobjectArray")
            elif type_queue[i] == "byte[]":
                fp.write("%s " % "jbyteArray")
            else:
                print "Error: unkown param type --> %s" % type_queue[i]
            fp.write("%s " % name_queue[i])
        fp.write(")\n")
    else:
        print "Error: parameter analysis fail --> %s" % interface_list[2]

def write_function_code_1(fp, interface_list):
    fp.write("{\n\tint ret = 0;\n")
    if interface_list[1] == "int":
        fp.write("\tjint response = 0;\n")
    elif interface_list[1] == "boolean":
        fp.write("\tjboolean response = 0;\n")
    elif interface_list[1] == "String":
        fp.write("\tjstring reply;\n")
        fp.write('\tchar response[4096] = "";\n')
    else:
        print "Error: unknown return type --> %s" % interface_list[1]


def write_function_code_2(fp, interface_list):
    type_queue = []
    name_queue = []
    parameter = interface_list[2].split(' ')
    if len(parameter) == 1:
        fp.write('\n\tjoyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\\n");\n\n')
    elif len(parameter) > 1:
        for i in range(len(parameter)):
            if i % 2 == 0:
                type_queue.append(parameter[i])
            else:
                name_queue.append(parameter[i])
        if len(type_queue) != len(name_queue):
            print "Error: parameter analysis fail --> %s" % interface_list[2]

        flag = 1
        for i in range(len(type_queue)):
            if name_queue[i][-1] != ',':
                name = name_queue[i]
            else:
                name = name_queue[i][:-1]
            if type_queue[i] == "int" or type_queue[i] == "boolean":
                pass
            elif type_queue[i] =="String" or type_queue[i] == "BundleContext":
                    fp.write("\tconst char* %sStr = NULL;\n" % name)
            elif type_queue[i] == "byte[]":
                    fp.write("\tjbyte* %sByte = NULL;\n" % name)
            elif type_queue[i] == "String[]":
                if flag:
                    flag = 0
                    fp.write("\tint i = 0;\n")
                    fp.write("\tjstring str;\n")
                    fp.write("\tconst char *chars = NULL;\n")
                fp.write("\tint %sNum = 0;\n" % name)
                fp.write("\tchar *%sList[256] = {0};\n" % name)
            else:
                print "Error: unknown parameter type --> %s" % type_queue[i]
        fp.write('\n\tjoyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\\n");\n\n')
    else:
        print "Error: parameter analysis fail --> %s" % interface_list[2]

def write_function_code_3(fp, interface_list):
    type_queue = []
    name_queue = []
    parameter = interface_list[2].split(' ')
    if len(parameter) == 1:
        pass
    elif len(parameter) > 1:
        for i in range(len(parameter)):
            if i % 2 == 0:
                type_queue.append(parameter[i])
            else:
                name_queue.append(parameter[i])
        if len(type_queue) != len(name_queue):
            print "Error: parameter analysis fail --> %s" % interface_list[2]

        for i in range(len(type_queue)):
            # if name_queue[i][-1] == ',':
            #     print "11 " + name_queue[i][:-1]
            # else:
            #     print "22 " + name_queue[i]
            if type_queue[i] == "int" or type_queue[i] == "boolean":
                pass
            elif type_queue[i] == "String" or type_queue[i] == "BundleContext":
                if name_queue[i][-1] == ',':
                    fp.write('\t%sStr = (char*)(*env)->GetStringUTFChars(env, %s, NULL);\n' % (name_queue[i][:-1], name_queue[i][:-1]))
                else:
                    fp.write('\t%sStr = (char*)(*env)->GetStringUTFChars(env, %s, NULL);\n' % (name_queue[i], name_queue[i]))
            elif type_queue[i] == "byte[]":
                if name_queue[i][-1] == ',':
                    fp.write('\t%sByte = (*env)->GetByteArrayElements(env, %s, NULL);\n' % (name_queue[i][:-1], name_queue[i][:-1]))
                else:
                    fp.write('\t%sByte = (*env)->GetByteArrayElements(env, %s, NULL);\n' % (name_queue[i], name_queue[i]))
            elif type_queue[i] == "String[]":
                if name_queue[i][-1] == ',':
                    fp.write('\t%sNum = (*env)->GetArrayLength(env, %s);\n' % (name_queue[i][:-1], name_queue[i][:-1]))
                    fp.write('''\tfor (i=0; i<%sNum; i++)
    {
        %sList[i] = malloc(256 * sizeof(char));
        str = (jstring)(*env)->GetObjectArrayElement(env, %s, i);
        chars = (*env)->GetStringUTFChars(env, str, NULL);
        strncpy(%sList[i], chars, sizeof(%sList[i]));
        (*env)->ReleaseStringUTFChars(env, str, chars);
    }
\n''' % (name_queue[i][:-1], name_queue[i][:-1], name_queue[i][:-1], name_queue[i][:-1], name_queue[i][:-1]))
                else:
                    fp.write('\t%sNum = (*env)->GetArrayLength(env, %s);\n' % (name_queue[i], name_queue[i]))
                    fp.write('''\tfor (i=0; i<%sNum; i++)
    {
        %sList[i] = malloc(256 * sizeof(char));
        str = (jstring)(*env)->GetObjectArrayElement(env, %s, i);
        chars = (*env)->GetStringUTFChars(env, str, NULL);
        strncpy(%sList[i], chars, sizeof(%sList[i]));
        (*env)->ReleaseStringUTFChars(env, str, chars);
    }
\n''' % (name_queue[i], name_queue[i], name_queue[i], name_queue[i], name_queue[i]))

def write_function_code_4(fp, interface_list):
    index = fp.name.rindex('_') + 1
    name = fp.name[index:-5]
    fp.write("\n\tret = joyme_cmcc_%s(" % name)

    if interface_list[1] == "int":
        fp.write("&response, ")
    elif interface_list[1] == "boolean":
        fp.write("&response, ")
    elif interface_list[1] == "String":
        fp.write('response, ')
    else:
        print "Error: unknown return type --> %s" % interface_list[1]

    type_queue = []
    name_queue = []
    parameter = interface_list[2].split(' ')
    if len(parameter) == 1:
        pass
    elif len(parameter) > 1:
        for i in range(len(parameter)):
            if i % 2 == 0:
                type_queue.append(parameter[i])
            else:
                name_queue.append(parameter[i])
        if len(type_queue) != len(name_queue):
            print "Error: parameter analysis fail --> %s" % interface_list[2]

        for i in range(len(type_queue)):
            if name_queue[i][-1] != ',':
                name = name_queue[i]
            else:
                name = name_queue[i][:-1]
            if type_queue[i] == "int" or type_queue[i] == "boolean":
                fp.write("%s, " % name)
            elif type_queue[i] =="String" or type_queue[i] == "BundleContext":
                fp.write("%sStr, " % name)
            elif type_queue[i] == "byte[]":
                fp.write("%sByte, " % name)
            elif type_queue[i] == "String[]":
                fp.write("%sList, %sNum, " % (name, name))
            else:
                print "Error: unknown parameter type --> %s" % type_queue[i]
    else:
        print "Error: parameter analysis fail --> %s" % interface_list[2]
    fp.seek(-2, 1)
    fp.write(");\n\n")

def write_function_code_5(fp, interface_list):
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
        if len(type_queue) != len(name_queue):
            print "Error: parameter analysis fail --> %s" % interface_list[2]

        for i in range(len(type_queue)):
            if name_queue[i][-1] != ',':
                name = name_queue[i]
            else:
                name = name_queue[i][:-1]
            if type_queue[i] == "int" or type_queue[i] == "boolean" \
            or type_queue[i] == "String" or type_queue[i] == "BundleContext":
                pass
            elif type_queue[i] == "byte[]":
                fp.write("\t(*env)->ReleaseByteArrayElements(env, %s, %sByte, 0);\n\n" % (name, name))
            elif type_queue[i] == "String[]":
                fp.write("""\tfor (i=0; i<%sNum; i++)
    {
        free(%sList[i]);
        %sList[i] = NULL;
    }
\n""" % (name, name, name))
    else:
        print "Error: parameter analysis fail --> %s" % interface_list[2]

    fp.write('''
    if (0 == ret)
    {
        joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: leave============>OK\\n");
    }
    else
    {
        joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: leave============>ERROR\\n");
    }\n\n''')
    if interface_list[1] == "int" or interface_list[1] == "boolean":
        fp.write("\treturn response;\n")
    elif interface_list[1] == "String":
        fp.write('\treply = (*env)->NewStringUTF(env, response);\n')
        fp.write("\treturn reply;\n")
    else:
        print "Error: unknown return type --> %s" % interface_list[1]

    fp.write("}\n")



def write_code(package_name, class_name, interface_name, interface_list):
    file_path = '%s/Java_com_chinamobile_smartgateway_%s_%sImp_%sJni.c' % (root, package_name, class_name, interface_name)
    with open(file_path, 'w') as fp:
        # print "Writing: " + file_path
        write_head(fp)
        write_function_name(fp, interface_list)
        write_function_param(fp, interface_list)
        write_function_code_1(fp, interface_list)   # return declaration
        write_function_code_2(fp, interface_list)   # paramter declaration
        write_function_code_3(fp, interface_list)   # paramter preprocess
        write_function_code_4(fp, interface_list)   # call joyme_cmcc function
        write_function_code_5(fp, interface_list)   # release resoucres
    fp.close()

def write_bundle_code(json_obj):
    for package_name in json_obj:
        if not package_name == 'comment':
            for class_name in json_obj[package_name]:
                for interface_name in json_obj[package_name][class_name]:
                    write_code(package_name, class_name, interface_name, json_obj[package_name][class_name][interface_name])    # called counts 151.

if __name__ == '__main__':
    if not os.path.exists(root):
        os.mkdir(root)
    json_obj = get_json_obj()
    write_bundle_code(json_obj)
