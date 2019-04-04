#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,vector<int>> m;
        map<int,vector<int>>::iterator it;
        if(nums.size() <2)
            return false;
        for(int i=0;i<nums.size();++i) {
            it = m.find(nums.at(i));
            if(it == m.end()) {
                vector<int> v;
                v.push_back(0);
                v.push_back(i);
                m.insert(pair<int,vector<int>>(nums.at(i),v));
            }
            else {
                if(it->second.at(0) == 0) {
                    it->second.at(0) = i - it->second.at(1);
                    it->second.at(1) = i;
                }
                else {
                    if(it->second.at(0) > (i-it->second.at(1))) {
                        it->second.at(0) = i-it->second.at(1);
                    }
                    it->second.at(1) = i;
                }                    
            }
        }
        int t=0;
        for(it=m.begin();it!=m.end();++it) {
            if(it->second.at(0) == 0)
                continue;
            else {
                if(t==0)
                    t = it->second.at(0);
                else {
                    if (t>it->second.at(0))
                        t = it->second.at(0);
                }
            }                
        }
        if(t == 0)
            return false;

        if(t <= k)
            return true;
        else
            return false;

    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




