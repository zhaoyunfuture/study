#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int i = 0;

        while(z!=0){
            if(z%2 != 0){
                i++;          
            }
            z /= 2;           
        }      
        return i;
    }
};
int main(int argc, char* argv[])
{
  
	return 0;
}




