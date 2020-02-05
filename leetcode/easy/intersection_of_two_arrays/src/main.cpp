#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        set<int> s;
        set<int> s1;
        set<int>::iterator it;
        if(nums1.size()==0 || nums2.size()==0)
            return v;
        for(int i=0;i<nums1.size();++i){
            it = s.find(nums1.at(i));
            if(it == s.end())
                s.insert(nums1.at(i));
        }
        for(int j=0;j<nums2.size();++j){
            it = s.find(nums2.at(j));
            if(it != s.end())
                s1.insert(nums2.at(j));
        }
        for(it=s1.begin();it!=s1.end();++it)
            v.push_back(*it);
        return v; 
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




