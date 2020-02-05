#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
	public:
		int min(vector<int>& cost, int index, int size) {
			if(index == size-1 || index == size-2)
				return cost.at(index);
			int a = min(cost, index+1, size);
			int b = min(cost, index+2, size);
			return a<b?a+cost.at(index):b+cost.at(index);
		}
		int minCostClimbingStairs(vector<int>& cost) {
			int size = cost.size();
			int a = min(cost,0,size);
			int b = min(cost,1,size);

			return a>b?b:a;
		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




