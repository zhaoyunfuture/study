#ifndef _ALLOCA_HPP_
#define _ALLOCA_HPP_
#include <cstddef>
#include <iostream>
#include <string.h>
using namespace std;

class allocA
{
    public:
        void* allocate(size_t size)
        {
            cout << "allocate from A" << endl;
            return malloc(size);
        }
        static void deallocate(void* ptr)
        {
            cout << "deallocate from A" << endl;
            free(ptr);
        }
};

#endif
