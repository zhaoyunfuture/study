#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n==0)
            return false;
        if (n==1)
            return true;
        while(n%3==0) {
            n /= 3;
            if(n==1)
                return true;
        }
        return false;

    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




