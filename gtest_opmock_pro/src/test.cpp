#include<gtest/gtest.h>
#include<map>
#include<iostream>

#include "test.hpp"
using namespace std;

static Student *s;

void Student::setAge(int a){
    age = a;
}
void Student::print(){
    cout<<"*********** "<<age<<" **********"<<endl;;
}
//在第一个test之前，最后一个test之后调用SetUpTestCase()和TearDownTestCase()
class TestMap:public testing::Test
{
public:
    static void SetUpTestCase()
    {
        cout<<"SetUpTestCase()"<<endl;
    s=new Student(23);
    }
 
    static void TearDownTestCase()
    {
    delete s;
        cout<<"TearDownTestCase()"<<endl;
    }
    void SetUp()
    {
        cout<<"SetUp() is running"<<endl;
         
    }
    void TearDown()
    {
        cout<<"TearDown()"<<endl;
    } 
};
 
TEST_F(TestMap, Test1)
 {
 
    // you can refer to s here
    s->print();
}
