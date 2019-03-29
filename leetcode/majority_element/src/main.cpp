#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        std::map<int, int> v;   
        std::map<int, int>::iterator it;
        int key;
        if(size ==1)
            return nums.at(0);

        for(int i=0;i<size;++i)
        {
            it = v.find(nums.at(i));
            if (it == v.end())
                v.insert (std::pair<int,int>(nums.at(i),1));
            else
            {
                it->second +=1;
                if(it->second > size/2)
                {
                    key = nums.at(i);
                    break;
                }
            }
        }
        return key;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




