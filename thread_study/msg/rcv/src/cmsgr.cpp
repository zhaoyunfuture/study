#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/msg.h>
#include "cmsg.h"

int main()
{
	int running = 1;
	//int msgid = -1;
	struct msg_st data;
	long int msgtype = 3; //注意1
	Cmsg omsg(111);
	//建立消息队列
	printf("msgid_rece=%d\n",omsg.get_msgid());	
	//从队列中获取消息，直到遇到end消息为止
	while(running)
	{
		if(-1 == omsg.msg_rece(&data,MAX_TEXT+sizeof(int),msgtype))
		{
			fprintf(stderr, "msgrcv failed with errno: %d\n", errno);
			exit(EXIT_FAILURE);
		}
		printf("You wrote type:%d,text= %s\n",data.type,data.text);
		//遇到end结束
		if(strncmp(data.text, "end", 3) == 0)
			running = 0;
	}
	//删除消息队列
	//if(msgctl(msgid, IPC_RMID, 0) == -1)
//	{
//		fprintf(stderr, "msgctl(IPC_RMID) failed\n");
//		exit(EXIT_FAILURE);
//	}
	exit(EXIT_SUCCESS);
}
