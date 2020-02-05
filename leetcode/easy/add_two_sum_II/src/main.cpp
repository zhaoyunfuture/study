#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
	public:
		vector<int> twoSum(vector<int>& numbers, int target) {
			vector<int> r;
			int size = numbers.size();
			if(size == 0)
				return r;
			bool find = false;
			for(int i = 0;i<size;++i)
			{
				for(int j = i+1;j<size;++j)
				{
					if(numbers.at(i)+numbers.at(j) == target)
					{
						r.push_back(i+1);
						r.push_back(j+1);
						find = true;
						break;
					}
					else if(numbers.at(i)+numbers.at(j) > target)
						break;
					else 
						continue;
				}
				if(find)
					break;
			}
			return r;
		}
};
int main(int argc, char* argv[])
{
  
	return 0;
}




