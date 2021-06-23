#ifndef __TEST_HPP_
#define __TEST_HPP_

class Student{
public:
    Student(){
        age=0;
    }
    Student(int a){
        age=a;
    }
    void setAge(int age);
    void print();
private:
    int age;
};

#endif
