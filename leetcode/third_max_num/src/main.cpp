#include <string.h>
#include <string>
#include <set>
#include <vector>
#include <iostream>
using namespace std;
#if 0
class compare
{
	public:
		bool operator()(const int& left, const int& right)
		{
			return left > right;
		}
};//this will cause compile error: comparison object must be invocable with two arguments of key type
#endif

struct classcomp {
	bool operator() (const int& lhs, const int& rhs) const
	{return lhs>rhs;}
};
class Solution {
	public:
		int thirdMax(vector<int>& nums) {
			if(nums.size()==1)
				return nums.at(0);
			else if(nums.size()==2)
				return nums.at(0)>nums.at(1)?nums.at(0):nums.at(1);
			else{
				set<int,classcomp> s;
				set<int>::iterator it;
				for(int i=0;i<nums.size();++i){
					s.insert(nums.at(i));
				}
				it = s.begin();
				if(s.size()>=3){
					it++;
					it++;
					return *it;
				}else
					return *it; 
			}
		}
};

int main(int argc, char* argv[])
{
	set<int,classcomp> s;
	set<int>::iterator it;
	s.insert(1);
	s.insert(2);
	s.insert(2);
	s.insert(3);
	cout << s.size() << endl;
	for (it=s.begin(); it!=s.end(); ++it)
		std::cout << ' ' << *it;

	cout << endl;
	it=s.begin();
	it++;
	it++;
	cout << *(it) << endl;
	return 0;
}




