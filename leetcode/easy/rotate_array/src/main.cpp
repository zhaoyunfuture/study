#include <string.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		void rotate(vector<int>& nums, int k) {
			int t;
			while(k)
			{
				t = *(nums.end()-1);
				nums.insert(nums.begin(),t);
				nums.pop_back();
				k--;
			}
		}
};

int main(int argc, char* argv[])
{
    vector<int> n;
	n.push_back(1);
	n.push_back(2);
	n.push_back(3);
	Solution s;
	s.rotate(n,2);
	for(int i=0;i<n.size();++i)
	{
		cout << n.at(i) << endl;
	}
	return 0;
}




