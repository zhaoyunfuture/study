#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int recurse(int i, vector<int>& nums) {
        if(i>(nums.size()-1))
            return 0;
        else {
            int a = recurse(i+2,nums);
            int b = recurse(i+3,nums);
            return a>b? a+nums.at(i):b+nums.at(i);
        }

    }
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int a = recurse(0,nums);
        int b = recurse(1,nums);
        return a>b?a:b;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




