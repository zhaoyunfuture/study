#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int actual_sum = 0;
        int expect_sum = (1+size)*size/2;
        if(size == 0)
            return 0;
        else {
            for(int i=0;i<size;++i)
                actual_sum +=nums.at(i);

            return expect_sum-actual_sum; 
        }

    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




