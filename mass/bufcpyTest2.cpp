/*************************************************************************
    > File Name: bufcpy2.cpp
    > Author: Jacob
    > Mail: zyfuture@qq.com 
    > Created Time: 2016年05月14日 星期六 23时12分46秒
 ************************************************************************/

#include <string.h>
#include <string>
#include <stdio.h>
#include<iostream>
#include "bufcpy.h"
using namespace std;

int main(){
/*	
	CBufTest cbuf;
	char test[10]="test test";
	char test1[20]="test1 test1";
	cbuf.setBuf(test,strlen(test));
	printf("cbuf = %s\n",cbuf.getBuf());
	std::string str("hello");
	const char * name = ".com";
	const char namebuf[10] = ".mmm";
	str.append(name);
	printf("str = %s\n",str.c_str());
	str.append(namebuf);
	printf("str = %s\n",str.c_str());
	CBufTest::get_instance()->setBuf(test1,strlen(test1));
*/
	printf("CBuf = %s\n",CBufTest::get_instance()->getBuf());
	return 0;
}

