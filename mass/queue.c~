#include "SPQueue.h"

int SqPqueue::PQueuefull()
{
return count==MAXSIZE;//相等，返回1
}
void SqPqueue::InsertSQ(datatype e)
{
if(PQueuefull())//如果为1，就是真
{
cerr<<"队列已满\n";
exit(1);
}
data[count] = e;
count++;
}
int SqPqueue::PQueueEmpty()
{
return count==0;
}
//外部函数，在类中已声明为友元，可以访问datatype
//重载太帅了，友元太好了
int operator < (datatype &a,datatype &b)
{
return a.priority < b.priority;//重载了<符号的定义
}
datatype SqPqueue::DeQueue()
{
if(PQueueEmpty())
{
cerr<<"队列为空\n";
exit(1);
}
datatype min = data[0];//开始选data[0]作为优先级最高的元素
int minidex = 0;//选minidex作为优先级最高的下标

//选出优先级最高的元素
for(int i = 0; i<count; i++)
//data[i]<min <=> data[i].priority<min.priority
if(data[i]<min)//如果没有重载<符号的话，肯定会出错的
{             //因为库本身定义的<符号，不是我们所需数据类型的比较
min = data[i];
minidex = i;
}
//删除后，依次往前挪动
for(int j = minidex;j<count-1;j++)
data[j] = data[j+1];
count--;
return min;//返回优先级最高的元素
}
