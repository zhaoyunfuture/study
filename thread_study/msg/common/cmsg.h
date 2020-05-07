#ifndef CMSG_ST_H
#define CMSG_ST_H
#include<iostream>
#include<sys/msg.h>
#define MAX_TEXT 512
using namespace std;

struct msg_st{
	long int msg_type;
	int type;
	char text[MAX_TEXT];
};
class Cmsg{
public:
	Cmsg();
	Cmsg(key_t k=123):key(k){msgid = this->msg_init(k);}	
	int msg_init(key_t key);
	int msg_send(msg_st *data,int length);
	int msg_rece(msg_st *data,int length, long int msgtype);
	int get_msgid(){return msgid;}
private:
	msg_st data;
	int msgid;
	key_t key;
};

#endif
