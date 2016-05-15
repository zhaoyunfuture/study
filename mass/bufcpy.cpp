/*************************************************************************
    > File Name: bufcpy.cpp
    > Author: Jacob
    > Mail: zyfuture@qq.com 
    > Created Time: 2016年05月14日 星期六 10时32分44秒
 ************************************************************************/
#include <string.h>
#include <string>
#include <stdio.h>
#include<iostream>
#include "bufcpy.h"
using namespace std;
CBufTest *CBufTest::pCBufTest = NULL;
CBufTest *CBufTest::get_instance(){
	if(NULL == CBufTest::pCBufTest){
		CBufTest::pCBufTest = new CBufTest();
	}
	return CBufTest::pCBufTest; 
}
int CBufTest::setBuf(const char * p_data,int length){
	if(length > MAX_BUF_LENGTH){
		return -1;
	}
	memset(buf,0,MAX_BUF_LENGTH);
	memcpy(buf,p_data,length);
	return 0;
}

