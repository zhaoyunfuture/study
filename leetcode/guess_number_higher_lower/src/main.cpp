#include <string.h>
#include <string>
#include <iostream>
using namespace std;
// Forward declaration of guess API.
// // @param num, your guess
// // @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
 
int guess(int num);

class Solution {
public:
    int recursion(int min,int max){
        if(guess(min)==0)
            return min;
        if(guess(max)==0)
            return max;
        int mid = min+(max-min)/2;
        if(guess(mid)==0)
            return mid;
        else if(guess(mid)==1)
            return recursion(mid,max);
        else
            return recursion(min,mid);
    }
    int guessNumber(int n) {
        return recursion(1,n);
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




