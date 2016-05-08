/*************************************************************************
    > File Name: al.c
    > Author: Jacob
    > Mail: zyfuture@qq.com 
    > Created Time: 2016年04月16日 星期六 07时39分25秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>

int main()
{
	int i;
	unsigned oidTable[8]={65,76,67,76,248,190,7,45};
	char tempStr[9];
	char tempStr1[8]={65,76,67,76,248,190,7,45};
	printf("sizeof tempstr = %d\n",sizeof(tempStr));
	memset(tempStr,'\0',sizeof(tempStr));
	memcpy(tempStr,(char*)oidTable,16);
	for(i=0;i<16;i++){
		printf("%c",tempStr[i]);
	}
	printf("\n");
	for(i=0;i<8;i++){
		printf("%c",tempStr1[i]);
	}
	printf("\n");
}
