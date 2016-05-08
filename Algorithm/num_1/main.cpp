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
	int input_num;
	int i,key=1,sum=0,temp,total=0;
	cin >> input_num;
	cout << "you input the num is --> " << input_num << endl;
    while(key<input_num){
		for(i=key;i<input_num;i++){
			sum	+=i;
			if(sum==input_num){
				total++;
				temp = key;
				while(temp<=i){
				 printf("%d ",temp);
				 temp++;				
				}
				 printf("\n");
			}
			if(sum>input_num)
				break;
		}	
		key++;
		sum=0;
	}
	//printf("total=%d\n",total);
	if(0==total){
		printf("NONE\n");
	}	
	return 0;			
}


