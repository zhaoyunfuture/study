#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    struct comp {
        bool operator() (const int& i,const int& j)const { return (i<j);}
    };
    vector<int> findErrorNums(vector<int>& nums) {
        set<int,comp> s;
        set<int,comp>::iterator sit;
        vector<int> v;
        for(int i=0;i<nums.size();++i) {
            sit = s.find(nums.at(i));
            if(sit == s.end())
                s.insert(nums.at(i));
            else
                v.push_back(nums.at(i));
        }
        int j=1;
        bool notlastone = false;
        for(sit=s.begin();sit!=s.end();sit++) {
            if(*sit != j) {
                v.push_back(j);
                notlastone = true;
                break;
            }
            j++;
        }
        if(!notlastone)
            v.push_back(nums.size());

        return v;        
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




