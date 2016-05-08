#include<iostream>
using namespace std;
#define MAXSIZE 6 //最大队列长度为6

typedef struct Datatype//这个改成DataType就错了。纠结
{
int taskNo;//任务号
int priority;//优先级
}datatype;
class SqPqueue
{
public:
SqPqueue(){count = 0;}
~SqPqueue(){}
int PQueuefull();//判断队满
void InsertSQ(datatype);//插入队列
int PQueueEmpty();//判断队空
datatype DeQueue();//删除队列
//重载关系运算符<,申明为友元,friend关键字可以让一个外部方法或者/
//一个外部类访问一个类本身的私有和保护成员
friend int operator <(datatype &,datatype &);
private:
datatype data[MAXSIZE];
int count;//计数器
};
