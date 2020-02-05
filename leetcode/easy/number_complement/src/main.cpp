#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int r = 0;
        int i = 0;
        int k = num;
        while(k!=0) {
            if(k%2 == 0)
                r += 1 << i;
            i++;
            k /= 2;
        }
        return r;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




