#include <string.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int maxProfit(vector<int>& prices) {
			int max = 0;
			for(int i=0;i<prices.size();++i)
			{
				bool skip = false;
				bool finish = false;
				int a = 0;
				for(int j=i+1;j<prices.size();++j)
				{
					int b = prices.at(j) - prices.at(i);
					if(b < 0)
					{
						if(j == i+1)
							break;
						else
						{
							i = j;
							skip = true;
							break;
						}
					}
					if(b > a)
					{
						a = b;
						if(j == prices.size()-1)
							finish = true;	
					}
					else
					{
						i = j;
						skip = true;
						break;
					}
				}
				max += a;
				if(skip)
					i--;
				if(finish)
					break;
			}
			return max;
		}
};

int main(int argc, char* argv[])
{
	Solution s; 
	int t[] = {1,2,4,2,5,7,2,4,9,0};
	vector<int> v (t, t + sizeof(t) / sizeof(int));
    cout << s.maxProfit(v) <<endl;
	return 0;
}




