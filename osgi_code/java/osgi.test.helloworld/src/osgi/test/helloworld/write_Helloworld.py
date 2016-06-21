#!/usr/bin/python2
# -*- coding:utf-8 -*-

import os
import sys
import json


json_file = "package_class_interface.json"
target_file = "HelloWorld.java.temp"


def get_json_obj():
    with open(json_file) as fp:
        json_obj = json.loads(fp.read())
    return json_obj


def write_code(fp, json_obj):
    i = 0
    j = 0
    for package_name in json_obj:
        if not package_name == 'comment':
            for class_name in json_obj[package_name]:
                i += 1
                for interface_name in json_obj[package_name][class_name]:
                    j += 1
                    fp.write("//System.out.println(hello_%d.%s());\n" % (i, interface_name))
                    fp.write("//System.out.println(\"--------------------------------->%d\");\n" % j)


def main():
    json_obj = get_json_obj()
    with open(target_file, "w") as fp:
        write_code(fp, json_obj)


if __name__ == '__main__':
    main()
