#include <string.h>
#include <string>
#include <iostream>
using namespace std;

ass Solution {
public:
    struct mycomp {
        bool operator() (const int& lhs, const int& rhs) const
        {return lhs<rhs;}
    };
    int arrayPairSum(vector<int>& nums) {
        std::map<int,int,mycomp> m;
        std::map<int,int,mycomp>::iterator mit;
        if(nums.size()==0)
            return 0;

        for(int i=0;i<nums.size();++i) {
            mit = m.find(nums.at(i));
            if(mit == m.end()) {
                m.insert(pair<int,int>(nums.at(i),1));
            }
            else {
                mit->second ++;                
            }
        }
        int r=0;
        vector<int> v;
        for(mit=m.begin();mit!=m.end();mit++) {
            int num = mit->second;
            for(int j=0;j<num;++j)
                v.push_back(mit->first);            
        }
        for(int k=0;k<v.size();k+=2)
            r += v.at(k);
        return r;
        #if 0
        if(!nums.size()) return 0;
        if(nums.size() == 2) return min(nums[0], nums[1]);
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i=0; i < nums.size(); i+=2) sum += nums[i];
        return sum;
        #endif
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




