/*************************************************************************
    > File Name: msg.h
    > Author: Jacob
    > Mail: zyfuture@qq.com 
    > Created Time: 2016年05月08日 星期日 15时47分23秒
 ************************************************************************/

#include<iostream>
#include<sys/msg.h>
#define MAX_TEXT 512
int msgid = -1;
using namespace std;

struct msg_st{
	long int msg_type;
	int type;
	char text[MAX_TEXT];
};

int msg_init(){
	msgid = msgget((key_t)123, 0666 | IPC_CREAT);
	return msgid;
}

int msg_send(msg_st *data,int length){
	if(msgsnd(msgid, (void*)data, length, 0) == -1)
		return -1;
	else
		return length;
}

int msg_rece(msg_st *data,int length, long int msgtype){
	if(msgrcv(msgid, (void*)data, length, msgtype, 0) == -1)
		return -1;
	else
		return length;
}
