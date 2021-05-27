#ifndef _ALLOCB_HPP_
#define _ALLOCB_HPP_
#include <cstddef>
#include <iostream>
#include <string.h>
using namespace std;

class allocB
{
    public:
        void* allocate(size_t size)
        {
            cout << "allocate from B" << endl;
            return malloc(size);
        }
        static void deallocate(void* ptr)
        {
            cout << "deallocate from B" << endl;
            free(ptr);
        }
};

#endif
