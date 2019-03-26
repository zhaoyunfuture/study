#include <string.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums.at(0);
        int key=0;;
        bool find = true;
        for(vector<int>::iterator ita = nums.begin();ita!=nums.end();++ita)
        {
            find = true;
            for(vector<int>::iterator itb = ita+1;itb!=nums.end();++itb)
            {
                if(*ita == *itb)
                {
                    find = false;
                    nums.erase(itb);
                    break;
                }
            }
            if(find)
            {
                key = *ita;
                break;
            }
        }
        return key;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> a;
    a.push_back(2);
    a.push_back(2);
    a.push_back(1);
    int r = s.singleNumber(a);
    cout << r << endl;
	return 0;
}




