#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int size = nums.size();
        if(size ==0)
            return 0;
        if(size == 1)
            return 1;
        int max = 1;
        int t = 1;
        for(int i=1;i<size;++i) {
            if(nums.at(i)>nums.at(i-1)){
                t++;
            }else {                
                if(t>max)
                    max = t;
                t = 1;
            }
        }
        return max>t?max:t;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




