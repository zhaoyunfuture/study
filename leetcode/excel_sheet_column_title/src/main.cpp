#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
	public:
		string convertToTitle(int n) {
			string r;
			string t;
			string z{'Z'};
			if(n <= 0)
				return r;
			if(n==26)
				return z;
			bool flag = false;
			int s = n/26;
			int y = n%26;
			while(s||y)
			{
				if(y == 0)
					t='Z';
				else
					t = 'A'+y-1;
				r.insert(0,t);
				if(s==26)
				{
					flag = true;
					break;
				}
				else
				{
					if(y!=0)
						y = s%26;
					else
						y = (s-1)%26;
					s = s/26;
				}
			}
			if(flag)
				r.insert(0,z);
			return r;

		}
};

int main(int argc, char* argv[])
{
	Solution s;
	cout << s.convertToTitle(25) << endl;
	cout << s.convertToTitle(26) << endl;
	cout << s.convertToTitle(52) << endl;
	cout << s.convertToTitle(28) << endl;
	cout << s.convertToTitle(701) << endl;
	cout << s.convertToTitle(705) << endl;
	return 0;
}




