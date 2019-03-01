#! /usr/bin/env python
#coding=utf-8

from string import Template

class BuildData:

    def Init(self):
        filePath = './default.h'
        class_file = open(filePath, 'w')

        mycode = []

        # 加载模板文件
        template_file = open('def.tmp', 'r')
        tmpl = Template(template_file.read())

        # 模板替换
        mycode.append(tmpl.substitute(
            CLASSNAME = 'DEFAULT',
            Class_Name = 'Default',
            En_name = 'mystruct',
            Type = 'int',
            Name = 'value'))

        # 将代码写入文件
        class_file.writelines(mycode)
        class_file.close()

        print('ok')

if __name__ == '__main__':
    build = BuildData()
    build.Init()
