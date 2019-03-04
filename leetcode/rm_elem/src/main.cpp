#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return 0;

        vector<int>::iterator it = nums.begin();
        while(it != nums.end())
        {
            if(val == *it)
                nums.erase(it);
            else
            {
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
    cout << s.removeElement(n,2) <<endl;
	return 0;
}




