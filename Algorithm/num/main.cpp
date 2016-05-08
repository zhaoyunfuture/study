/*************************************************************************
    > File Name: main.c
    > Author: Jacob
    > Mail: zyfuture@qq.com 
    > Created Time: 2016年03月15日 星期二 21时53分06秒
 ************************************************************************/

#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int max_num;
	int i,j,k;
	cin >> max_num;
	cout << "you input the num is --> " << max_num << endl;
	for(i=1;i<=max_num;i++)
	{
		for(j=i+1;j<=max_num;j++)
		{
			for(k=j+1;k<=max_num;k++)
			{
				printf("i=%d,j=%d,k=%d\n",i,j,k);
			}
		}
	}	
	return 0;			
}


