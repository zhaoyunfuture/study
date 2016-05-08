/*************************************************************************
    > File Name: test.cpp
    > Author: Jacob
    > Mail: zyfuture@qq.com 
    > Created Time: 2016年05月08日 星期日 14时12分31秒
 ************************************************************************/

#include<iostream>
#include<event.h>
#include<sys/time.h>
#include<thread>
#include <unistd.h>
using namespace std;

void func(int fd,short event,void *arg){
	cout << "test" << endl;
}
int eve_func(){
	struct event ev;
	struct timeval tv;
	tv.tv_sec = 3;
	tv.tv_usec = 0;
	event_init();
	event_set(&ev,0,EV_PERSIST,func,NULL);
	evtimer_add(&ev,&tv);
	event_dispatch();
}

void print_hello(){
	sleep(25);
	cout << "hello" << endl;
}

int main(){
	std::thread func(eve_func);
	std::thread hello(print_hello);
	func.join();
	hello.join();
//	func = thread(eve_func);
//	eve_func();
	cout << "end" << endl;
	return 0;
}
