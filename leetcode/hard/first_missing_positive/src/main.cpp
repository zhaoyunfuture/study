#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
    public:
        struct comp {
            bool operator() (const int& lhs, const int& rhs) const
            {return lhs<rhs;}

        };
        int firstMissingPositive(vector<int>& nums) {
            set<int,comp> s;
            set<int,comp>::iterator sit;
            for(int i=0;i<nums.size();i++){
                s.insert(nums.at(i));

            }
            int res=1;
            for(sit=s.begin();sit!=s.end();sit++){
                if(*sit<1)
                    continue;
                else{
                    if(*sit!=res)
                        return res;
                    else
                        res++;

                }

            }
            return res;

        }

};
int main(int argc, char* argv[])
{
  
	return 0;
}




