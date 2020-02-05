#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
	public:
		int minMoves(vector<int>& nums) {
			int size = nums.size();
			int max,min;
			bool allsame = true;
			int sum = 0;
			if(size < 2)
				return 0;
			if(size == 2)
				return nums.at(0)>nums.at(1)?nums.at(0)-nums.at(1):nums.at(1)-nums.at(0);
			max = nums.at(0);
			min = nums.at(0);
			for(int i=0;i<size;++i){
				if(nums.at(i)!=nums.at(0))
					allsame = false;
				if(nums.at(i)>max)
					max = nums.at(i);
				if(nums.at(i)<min)
					min = nums.at(i);
				sum += nums.at(i);
			}
			if(allsame)
				return 0;
		    return sum-size*min;	
		}
};

int main(int argc, char* argv[])
{
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2147483647);
	cout << s.minMoves(v) << endl;
  
	return 0;
}




