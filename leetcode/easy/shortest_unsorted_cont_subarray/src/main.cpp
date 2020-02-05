#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
	public:
		struct mapcomp {
			bool operator() (const int& lhs, const int& rhs) const
			{return lhs<rhs;}
		};
		int findUnsortedSubarray(vector<int>& nums) {
			int size = nums.size();
			if(size==0)
				return 0;
			int prenum = nums.at(0);
			bool orignalAscend = true;
			map<int,int,mapcomp> m;
			map<int,int,mapcomp>::iterator mit;
			map<int,int,mapcomp>::reverse_iterator mrit;
			for(int i=0;i<size;++i) {
				if(prenum>nums.at(i))
					orignalAscend = false;
				prenum = nums.at(i);
				mit = m.find(nums.at(i));
				if(mit == m.end())
					m.insert(pair<int,int>(nums.at(i),1));
				else
					mit->second++;
			}
			if(orignalAscend)
				return 0;
			int first = 0;
			int end = 0;
			mit=m.begin();
			for(int j=0;j<size;++j) {
				if(nums.at(j)==mit->first){
					if(mit->second == 1){
						mit++;
						continue;
					}
					else
						mit->second--;
				}else{
					first = j;
					break;
				}       
			}
			mrit = m.rbegin();
			for(int k=size-1;k>0;--k) {
				if(nums.at(k)==mrit->first){
					if(mrit->second == 1){
						mrit++;
						continue;
					}
					else
						mrit->second--;
				}else{
					end = k;
					break;
				}       
			}        
			return end-first+1;

		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




