#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    struct classcomp {
      bool operator() (const int& lhs, const int& rhs) const
      {return lhs>rhs;}
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int,classcomp> m; 
        map<int,int,classcomp>::iterator mit;
        vector<int> out;
        if(nums.size()==0)
            return out;
        for(int i=0;i<k;i++){
            mit = m.find(nums.at(i));
            if(mit==m.end())
                m.insert(pair<int,int>(nums.at(i),1));
            else
                mit->second++;
        }
        out.push_back(m.begin()->first);
        for(int i=k;i<nums.size();i++){
            mit = m.find(nums.at(i-k));
            mit->second -=1;
            if(mit->second==0)
                m.erase(mit);
            mit = m.find(nums.at(i));
            if(mit==m.end())
                m.insert(pair<int,int>(nums.at(i),1));
            else
                mit->second++;
            out.push_back(m.begin()->first);
        }
        return out;
    }
};
int main(int argc, char* argv[])
{
  
	return 0;
}




