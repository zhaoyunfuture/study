/*************************************************************************
    > File Name: msg.h
    > Author: Jacob
    > Mail: zyfuture@qq.com 
    > Created Time: 2016年05月08日 星期日 15时47分23秒
 ************************************************************************/
#include<iostream>
#include"cmsg.h"
using namespace std;
/*
class Cmsg{
public:
	Cmsg();
	Cmsg(key_t k);
	int msg_init(key_t key);
	int msg_send(msg_st *data,int length){
	int msg_rece(msg_st *data,int length, long int msgtype){
private:
	msg_st data;
	key_t key;
	int msgid;
};
Cmsg::Cmsg(key_t k){
	msgid = this->msg_init(k);	
}
*/

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

