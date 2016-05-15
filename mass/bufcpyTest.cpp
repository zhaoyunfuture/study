/*************************************************************************
    > File Name: bufcpy2.cpp
    > Author: Jacob
    > Mail: zyfuture@qq.com 
    > Created Time: 2016年05月14日 星期六 23时12分46秒
 ************************************************************************/
#include <unistd.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <pthread.h>
#include "bufcpy.h"
#define VNAME (CBufTest::get_instance()->getvname()) 
using namespace std;

void *thread_func1(void * msg);
void *thread_func2(void * msg);

int main(){
	CBufTest cbuf;
	pthread_t thread1;
	pthread_t thread2;
	void *thread_result = NULL;
	int res = -1;
	int aa = 10;
	int msg;
	char test[10]="test test";
	char test1[20]="test1 test1";
	cbuf.setBuf(test,strlen(test));
	printf("cbuf = %s\n",cbuf.getBuf());
	std::string str("hello");
	std::string str1("hello---");
	std::string str2("hi---");
	vector<std::string>::iterator it;
	const char * name = ".com";
	const char namebuf[10] = ".mmm";
	str.append(name);
	printf("str = %s\n",str.c_str());
	str.append(namebuf);
	printf("str = %s\n",str.c_str());
	CBufTest::get_instance()->setBuf(test1,strlen(test1));
	printf("CBuf = %s\n",CBufTest::get_instance()->getBuf());
	
	CBufTest::get_instance()->getStr().append(name);
	printf("get str = %s\n",CBufTest::get_instance()->getStr().c_str());

	CBufTest::get_instance()->getint() = &aa;
	printf("get int = %d\n",*(CBufTest::get_instance()->getint()));

	CBufTest::get_instance()->getvname().push_back(str);
	CBufTest::get_instance()->getvname().push_back(str1);
	VNAME.push_back(str2);
	printf("vname size = %ld\n",CBufTest::get_instance()->getvname().size());
	for(it = CBufTest::get_instance()->getvname().begin();it != CBufTest::get_instance()->getvname().end(); it++ ){
		printf("vname = %s\n",(*it).c_str());
	}
	
	res = pthread_create(&thread1, NULL, thread_func1,&msg);
	if(res != 0)
	{
		printf("pthread_create1 failed\n");
	}

	res = pthread_create(&thread2, NULL, thread_func2,&msg);
	if(res != 0)
	{
		printf("pthread_create2 failed\n");
	}
	pthread_join(thread1, &thread_result);
	pthread_join(thread2, &thread_result);
	return 0;
}

void *thread_func1(void * msg)
{
	while(1)
	{
		sleep(3);
		printf("thread -one- CBuf = %s\n",CBufTest::get_instance()->getBuf());
	}
	
}

void *thread_func2(void * msg)
{
	int i = 0;
	char test1[12]="test one";
	char test2[12]="test two";
	char test3[12]="test three";
	char test4[12]="test four";
	char *test[4]={test1,test2,test3,test4};	
	while(1)
	{
		sleep(7);
		if(3 == i){
			CBufTest::get_instance()->setBuf(test[i],strlen(test[i]));
			i =0;
		}else{
			CBufTest::get_instance()->setBuf(test[i],strlen(test[i]));
			i++;
		}
	}
	
}
