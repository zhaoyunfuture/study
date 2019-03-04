#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int m = 0;
        if(nums.size() < 2)
            return nums.size();

        vector<int>::iterator it = nums.begin();
        m = *it;
        it++;
        while(it != nums.end())
        {
            if(m == *it)
                nums.erase(it);
            else
            {
                m = *it;
                it++;
            }
        }
        
        return nums.size();
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> n;
    n.push_back(1);
    n.push_back(1);
    n.push_back(4);
    n.push_back(2);
    n.push_back(2);
    n.push_back(2);
    n.push_back(3);
    n.push_back(3);
    cout << s.removeDuplicates(n) <<endl;
	return 0;
}




