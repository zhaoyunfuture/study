#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        if(target == 0)
            return 0;
        if(target < 0)
            target = target*-1;
        int sum=0, i;
        for(i=1;;i++){
            sum+=i;
            if(sum>=target)
                break;
        }
        int diff = sum - target;
        if(diff %2 ==0){
            return i;
        }
        else{
            i = i+1;
            if(i%2 != 0)
                return i;
        }
        return ++i;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




