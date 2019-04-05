#include <string.h>
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)
            return false;
        int t=n;
        while(t){
            if(t==1)
                return true;
            if(t%2 != 0)
                return false;
            t /= 2;
        }
        return true;
    }
};

int main(int argc, char* argv[])
{

    return 0;
}




