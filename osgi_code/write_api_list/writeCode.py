#!/usr/bin/python
# -*- coding:utf-8 -*-

import os
import sys
import json


def get_json_obj():
    with open("./package_class_interface.json") as fp:
        json_obj = json.loads(fp.read())
    fp.close()
    return json_obj


def write_api_list(json_obj, fp):
    for package_name in json_obj:
        if not package_name == 'comment':
            for class_name in json_obj[package_name]:
                    fp.write("\"%s.%s\",\n" % (package_name, class_name))


if __name__ == '__main__':
    with open("./api_list", "w") as fp:
        json_obj = get_json_obj()
        write_api_list(json_obj, fp)
