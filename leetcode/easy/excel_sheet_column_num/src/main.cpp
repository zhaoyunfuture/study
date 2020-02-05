#include <string.h>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
	public:
		int titleToNumber(string s) {
			int r = 0;
			int i = 0;
			int v = 0;
			char t;
			char a = 'A';
			for (std::string::reverse_iterator rit=s.rbegin(); rit!=s.rend(); ++rit)
			{
				   t = *rit;
				   v = t-a;
				   v +=1;
				   r += v*pow(26,i);
				   i++;
			}
			return r;
		}
};

int main(int argc, char* argv[])
{
	Solution s;
	string a{'B'};
	char bb = *(a.begin());
	char aa = 'A';
	int v = bb-aa;
	cout << v <<endl;
	cout << s.titleToNumber("ZY");
	return 0;
}




