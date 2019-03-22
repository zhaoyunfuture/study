#include <string.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int maxProfit(vector<int>& prices) {
			int a = 0;
			for(int i=0;i<prices.size();++i)
			{
				for(int j=i+1;j<prices.size();++j)
				{
					int b = prices.at(j) - prices.at(i);
					if(b > a)
						a = b;
				}
			}
			return a;
		}
};

int main(int argc, char* argv[])
{
	Solution s;  
	return 0;
}




