#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int lastMod = 0;
        int mod = 0;
        if(n<3)
            return true;
        lastMod = n%2;
        while(n/2 !=0){
            n /= 2;
            mod = n%2;
            if(mod == lastMod)
                return false;
            else
                lastMod = mod;
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




