#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
	public:
		uint32_t reverseBits(uint32_t n) {
			if (n == 0)
				return 0;
			if( n == UINT_MAX )
			    return UINT_MAX;
			uint32_t r=0;
			for(int i=31;i>=0;--i)
			{
				if(n%2)
					r += 1<<i;
				n /=2;
			}
			return r;
		}
};

int main(int argc, char* argv[])
{
    Solution s;	
	cout << s.reverseBits(43261596) << endl;;
	return 0;
}




