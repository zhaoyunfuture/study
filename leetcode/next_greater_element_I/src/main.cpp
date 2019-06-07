#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> r;
        std::map<int,int> m;
        std::map<int,int>::iterator  mit;
        int n1_len = nums1.size();
        int n2_len = nums2.size();

        if(n1_len == 0 || n2_len == 0)
            return r;
        bool find = false;
        for(int i=0;i<n2_len;++i) {
            find = false;
            for(int j=i+1;j<n2_len;++j){
                if(nums2.at(i)<nums2.at(j)) {
                    find = true;
                    m.insert(pair<int,int>(nums2.at(i),nums2.at(j)));
                    break;
                }                    
            }
            if(find)
                continue;
            else
                m.insert(pair<int,int>(nums2.at(i),-1));
        }
        for(int k=0;k<n1_len;++k) {
            mit = m.find(nums1.at(k));
            nums1.at(k) = mit->second;
        }
        return nums1;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




