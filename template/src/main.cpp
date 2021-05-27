#include <string.h>
#include <string>
#include <iostream>
#include "tmp.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    insta ins;
    char* p=NULL;
    p = (char*)ins.m_alloc->allocate(100);
    printf("p: %p\n",p);
    ins.m_alloc->deallocate(p);

    myString str1 = "test1"; 
    myStringlist strList;
    strList.push_back(str1);
    cout << strList.front() << endl;

	return 0;
}




