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
		int findPairs(vector<int>& nums, int k) {
			set<int,comp> s1,s2;
			set<int,comp>::iterator sit;

			for(int i=0;i<nums.size();++i) {
				sit = s1.find(nums.at(i));
				if (sit == s1.end()) {
					s1.insert(nums.at(i));
				}else {
					s2.insert(nums.at(i));
				}
			}
			int pair_num=0;        

			if(k == 0)
				return s2.size();
			if(k<0)
				return 0;
			for(sit=s1.begin();sit!=s1.end();++sit){
				if(s1.find(*sit+k)!=s1.end())
					pair_num++;
			}
			return pair_num;
		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




