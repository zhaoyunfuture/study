#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int add(int n) {
        vector<int> v;
        vector<int>::iterator it;
        int t = n;
        while(t/10 != 0 || t%10 != 0) {
            v.push_back(t%10);
            t /=10;
        }
        t = 0;
        for(it = v.begin();it!=v.end();++it) {
            t += *it;
        }
        return t;
    }
    int addDigits(int num) {
        int r = add(num);
        while(r>9)
            r = add(r);

        return r;


    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




