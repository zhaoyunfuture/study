#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int t = 0;
        int size = nums.size();
        if(size < 3)
            return -1;
        vector<int> sums;
        sums.push_back(nums.at(0));
        for(int i=1;i<size;++i) {
            sums.push_back( sums.at(i-1) + nums.at(i) );
        }
        sum = sums.at(size-1);
        if(sum-nums.at(0) == 0)
            return 0;
        for(int i=1;i<size-1;++i) {
            t = sum - nums.at(i);
            if(t%2 ==1 || t%2 ==-1)
                continue;
            if(sums.at(i-1) == t/2) {                
                return i;
            }
        }
        if(sums.at(size-2) == 0)
            return size-1;
        else
            return -1;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




