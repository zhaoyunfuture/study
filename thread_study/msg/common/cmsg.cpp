#include<iostream>
#include"cmsg.h"
using namespace std;

int Cmsg::msg_init(key_t key){
	int msgid;
	msgid = msgget(key, 0666 | IPC_CREAT);
	return msgid;
}

int Cmsg::msg_send(msg_st *data,int length){
	if(msgsnd(msgid, (void*)data, length, 0) == -1)
		return -1;
	else
		return length;
}

int Cmsg::msg_rece(msg_st *data,int length, long int msgtype){
	if(msgrcv(msgid, (void*)data, length, msgtype, 0) == -1)
		return -1;
	else
		return length;
}

