#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

bool compfunc (int i,int j) { return (i>j); }

class Solution {
	public:
		vector<string> findRelativeRanks(vector<int>& nums) {
			vector<string> r;
			vector<int> v;
			vector<int>::iterator vit;
			v = nums;
			int i=0;
			sort(v.begin(),v.end(),compfunc);
			for(vit = nums.begin();vit!=nums.end();++vit) {
				for(i=0;i<nums.size();++i) {
					if(*vit == v.at(i)) {
						switch (i) {
							case 0:r.push_back("Gold Medal");break;
							case 1:r.push_back("Silver Medal");break;
							case 2:r.push_back("Bronze Medal");break;
							default:r.push_back(to_string(i));break;
						}
					}
				}
			}
			return r;
		}
};

int main(int argc, char* argv[])
{
	vector<int> v;
	vector<int>::iterator vit;

	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(3);

	sort(v.begin(),v.end(),compfunc);
	for(vit=v.begin();vit!=v.end();++vit)
		cout << *vit << " " ;
	cout << endl;
	return 0;
}

#if 0
//push to leecode

class Solution {
	public:
		struct myclass {
			bool operator() (int i,int j) { return (i>j);}
		} comp;
		vector<string> findRelativeRanks(vector<int>& nums) {
			vector<string> r;
			vector<int> v;
			vector<int>::iterator vit;
			v = nums;
			int i=0;
			sort(v.begin(),v.end(),comp);
			for(vit = nums.begin();vit!=nums.end();++vit) {
				for(i=0;i<nums.size();++i) {
					if(*vit == v.at(i)) {
						switch (i) {
							case 0:r.push_back("Gold Medal");break;
							case 1:r.push_back("Silver Medal");break;
							case 2:r.push_back("Bronze Medal");break;
							default:r.push_back(to_string(i+1));break;
						}
					}
				}
			}
			return r;

		}
};
#endif


