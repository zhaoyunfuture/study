#include <iostream>
#include <string>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define MSG_SIZE 512

void *thread_func1(void *msg);
void *thread_func2(void *msg);

template <typename T>
class CircularQueue
{
public:
    explicit CircularQueue(int capacity) : m_capacity(capacity), m_head(0), m_tail(0)
    {
        m_array = new T[m_capacity + 1];
    }
    
    ~CircularQueue()
    {
        delete[] m_array;
        m_capacity = m_head = m_tail = 0;
    }
    
    bool IsFull()
    {
        int offset = (m_tail + 1) % (m_capacity + 1);
        
        return (offset == m_head);
    }
    
    bool IsEmpty()
    {
        return (m_tail == m_head);
    }
    
    void Push(const T& item)
    {
        if ( !IsFull() )
        {
            m_array[m_tail] = item;
            m_tail = (m_tail + 1) % (m_capacity + 1);
        }
    }
    
    T Pop()
    {
        if ( IsEmpty() )
        {
            return T();
        }
        
        int index = m_head;
        m_head = (m_head + 1) % (m_capacity + 1);
        
        return m_array[index];
    }
    
private:
    T* m_array; // 缓冲区队列
    int m_capacity; // 队列最大存储容量
    int m_head; // 队列头指针
    int m_tail; // 队列尾指针
};

CircularQueue<int> queue(5);

int main()
{
    int res = -1;
    pthread_t thread1;
    pthread_t thread2;
    char msg[MSG_SIZE];
    
    res = pthread_create(&thread1,NULL,thread_func1,msg);
    if(res != 0){
        printf("phread1 create failed\n");
        return -1;
    }
    
    res = pthread_create(&thread2,NULL,thread_func2,msg);
    if(res != 0){
        printf("phread2 create failed\n");
        return -1;
    }
    printf("main print ---\n");
    pthread_join(thread1, NULL); 
    pthread_join(thread2, NULL);
}

void *thread_func1(void *msg)
{
    while(1){
        sleep(1);
        printf("thread 1 func print ---\n");
        printf("queue is full? ---%d  queue is empty? ---%d\n",queue.IsFull(),queue.IsEmpty());
        printf("queue pop --- %d\n",queue.Pop());
    }
}

void *thread_func2(void *msg)
{
    while(1){
        sleep(4);
        printf("thread 2 func print ---\n");
        printf("queue is full? ---%d  queue is empty? ---%d\n",queue.IsFull(),queue.IsEmpty());
        queue.Push(5);
    }
} 
