#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
	public:
		int deepfind2(int n) {
			int r=0;
            while(n%2 == 0)
			{
				r++;
				n /= 2;
			}
			return r;
		}
		int deepfind5(int n) {
			int r=0;
            while(n%5 == 0)
			{
				r++;
				n /= 5;
			}
			return r;
		}
		int trailingZeroes(int n) {
			int two_five[2];
			two_five[0] = 1;
			two_five[1] = 0;
			if(n<5)
				return 0;
			else
			{
				for(int i=5;i<=n;++i)
				{
					two_five[0] += deepfind2(i);
					two_five[1] += deepfind5(i);
				}
			}
			if(two_five[0]<two_five[1])
				return two_five[0];
			else
				return two_five[1];
		}
};

int main(int argc, char* argv[])
{
    Solution s;
	cout << s.deepfind2(12) << endl;
	cout << s.deepfind5(25) << endl;
	cout << s.deepfind2(60) << endl;
	cout << s.deepfind5(60) << endl;
	cout << s.trailingZeroes(10) << endl;
	cout << s.trailingZeroes(1808548329) << endl;
	return 0;
}




