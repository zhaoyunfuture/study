#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
	public:
		int hammingWeight(uint32_t n) {
			if (n == 0)
				return 0;
			int r=0;
#if 0
			for(int i=31;i>=0;--i)
			{
				if(n%2)
					r += 1;
				n /=2;
			}
#endif
			while(n !=0 )
			{
				if(n%2)
					r += 1;
				n /=2;
			}
			return r;
		}
};

int main(int argc, char* argv[])
{
    Solution s;	
	cout << s.hammingWeight(7) << endl;;
	return 0;
}




