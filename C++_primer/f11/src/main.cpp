#include <string.h>
#include <string>
#include <iostream>
#include <functional>
#include "t.hpp"
using namespace std;

#define PTR(p) if(p) { \
                cout << #p << " is valid: " << p << endl; \
               } else {\
                cout << #p << " invalid" << endl; \
               }\

int main(int argc, char* argv[])
{
    a* a1= new a(10);
    t tt;
    t tt1;
    t tt2;
    t tt3;
    func a;
    func b;
    tt.set(1);
    tt1.set(2);
    cout << tt.get()<< endl;
    a = tt.getbyfunc();
    b = tt1.getbyfunc();
    cout << a() << endl;
    cout << b() << endl;

    cout << "a1: " << a1 << endl;
    tt1.setPtr(a1);
    tt2 = tt1;
    cout << "tt2 prt: " << tt2.getPtr() << endl;
    PTR(tt2.getPtr());
    tt3 = std::move(tt2);
    PTR(tt2.getPtr());
    PTR(tt1.getPtr());
    t tt4(std::move(tt1));
    PTR(tt1.getPtr());
    PTR(tt4.getPtr());
	return 0;
}




