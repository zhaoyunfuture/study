#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        set<int>::iterator it;

        if(nums.size() < 2)
            return false;
        for(int i=0;i<nums.size();++i)
        {
            if(s.find(nums.at(i)) == s.end())
            {
                s.insert(nums.at(i));
            }
            else
                return true;
        }
        return false;

    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




