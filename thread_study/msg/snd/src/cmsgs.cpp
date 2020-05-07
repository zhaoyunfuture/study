#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/msg.h>
#include <errno.h>

#include "cmsg.h"

int main()
{
	int running = 1;
	struct msg_st data;
	char buffer[MAX_TEXT];
	//建立消息队列
	Cmsg omsg(111);
	printf("msgid_send=%d\n",omsg.get_msgid());
	//向消息队列中写消息，直到写入end
	while(running)
	{
		//输入数据
		printf("Enter some text: ");
		fgets(buffer, MAX_TEXT, stdin);
		data.msg_type = 3;    //注意2
		strcpy(data.text, buffer);
		data.type = 1;
		//向队列发送数据
		if(omsg.msg_send(&data, MAX_TEXT+sizeof(int)) == -1)
		{
			fprintf(stderr, "msgsnd failed\n");
			exit(EXIT_FAILURE);
		}
		//输入end结束输入
		if(strncmp(buffer, "end", 3) == 0)
			running = 0;
		sleep(1);
	}
	exit(EXIT_SUCCESS);
}
