#include <string.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = 0;

        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums.at(0);

        max = nums.at(0);

        for(unsigned int i = 0;i < nums.size(); ++i)
        {
            for(unsigned int j = 0;j < (nums.size()-i);++j)
            {
                int t = 0;
                
                for(unsigned int k = j; k < j+i+1; ++k)
                {
                    t +=nums.at(k);
                }

                if(max < t)
                    max = t;

            }
        }

        return max;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> v;
    v.push_back(-2);
    v.push_back(1);
    v.push_back(-3);
    v.push_back(4);
    v.push_back(-1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(-5);
    v.push_back(4);

    cout << s.maxSubArray(v) << endl;
	return 0;
}




