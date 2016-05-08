#include<string.h>
#include<iomanip>

#include "SPQueue.h"

int main()
{
        //具有优先级队列
        SqPqueue MyQueue;
datatype task;
int id = 1,srandNo;
cout<<"输入产生随机数种子数："<<endl;
cin>>srandNo;
srand(srandNo);//初始化种子数
cout<<"****生成优先顺序队列****\n\n";
for(int i = 0;i<MAXSIZE;i++)
{
task.taskNo = i+1;
task.priority = rand()%10;//产生0到9之间的随机数
MyQueue.InsertSQ(task);
}
cout<<"****输出优先顺序队列****\n";
cout<<"序号　　任务号　　　优先级\n";
while(!MyQueue.PQueueEmpty())
{
cout<<setw(2)<<id;
task = MyQueue.DeQueue();//找到优先级最高的任务
cout<<setw(9)<<task.taskNo;
cout<<setw(12)<<task.priority<<endl;
id++;
}
int x;cout<<endl<<"为了让它停一下下";cin>>x;
}
