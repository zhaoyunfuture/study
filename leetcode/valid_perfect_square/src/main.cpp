#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        unsigned int j;
        if (num == 1)
            return true;
        for(int i=1;num>=i*i;){
            if(num == i*i)
                return true;
            j = i+1;
            if(j*j>INT_MAX)
                return false;
            else
                i++;
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




