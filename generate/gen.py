#! /usr/bin/env python
#coding=utf-8
import os,sys,re,traceback
from datetime import datetime
from string import Template
class Gen:
	def gen(self):
		tableName = 'students'
		className = '%sRedisDao' %  tableName.capitalize()
		filePath = 'include/%s.cpp' % className
		class_file = open(filePath,'w')
		lines = []

		template_file = open('cpp.tmp', 'r')
		tmpl = Template(template_file.read())

		lines.append(tmpl.substitute(
					CLASSNAME = className,
					TABLE_NAME = tableName,
					TABLE_NAME_UPPER = tableName.upper(), 
					GENE_DATE = datetime.now().strftime('%Y-%m-%d %H:%M:%S'),
					TABLE_ID = '115',
					EXPIRE_DATE = '06JUN14'))

		class_file.writelines(lines)
		class_file.close()
		print 'generate %s over. ~ ~' % filePath

if __name__ == '__main__':
    g = Gen()
    g.gen()
