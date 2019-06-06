#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        bool isconsecutive = false;
        int max = 0;
        int t = 0;
        for(int i=0;i<nums.size();++i) {
            if(isconsecutive && nums.at(i)==1)
                t++;
            else if (!isconsecutive && nums.at(i)==1) {
                t++;
                isconsecutive = true;
            }
            else {
                if(t>max)
                    max = t;
                t = 0;
                isconsecutive = false;
            }                
        }
        return max>t?max:t;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




