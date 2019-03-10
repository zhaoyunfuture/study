#include <string.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		std::vector<int>::iterator it1;
		std::vector<int>::iterator it2;
		int i = 0;
		bool flag = false;
		if(m == 0)
		{
			nums1.erase(nums1.begin(),nums1.begin()+nums1.size());
			for(it2 = nums2.begin();it2 != nums2.end(); ++it2)
			{
				nums1.push_back(*it2);
			}
			return;
		}
		for(it2 = nums2.begin();it2 != nums2.end(); ++it2)
		{
			it1 = nums1.begin();
			int j = 0;
			while(*it2 > *it1)
			{
				it1++;
				j++;
				if(j == (m+i-1) || m==1)
				{
					flag = true;
					break;
				}
			}
			if(flag)
			{
				if(m ==1)
				{
					nums1.pop_back();
					break;
				}
				int k = m+n-j-1;
				for(;k>0;k--)
				{
					nums1.pop_back();
				}
				break;
			}
			nums1.insert(it1,*it2);
			nums1.pop_back();
			i++;
		}
		for(;it2 != nums2.end(); ++it2)
		{
			nums1.push_back(*it2);
		}
	}
};


int main(int argc, char* argv[])
{
	Solution s;
    std::vector<int> v1;
    std::vector<int> v2;
	std::vector<int>::iterator it1;
#if 0
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(0);
	v1.push_back(0);
	v1.push_back(0);
	
	v2.push_back(2);
	v2.push_back(5);
	v2.push_back(6);
	s.merge(v1,3,v2,3);
#endif
	v1.push_back(1);
	v1.push_back(0);
	v2.push_back(2);
	s.merge(v1,1,v2,1);

	it1 = v1.begin();
	for(;it1!=v1.end();++it1)
	{
		cout << *it1 << endl;
	}
	return 0;
}




