#include <string.h>
#include <string>
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
	public:
		string tochar(int n) {
			if(n<10)
				return to_string(n);
			else{
				string t;
				t = 'a'+(n-10);
				return t;
				}
		}
		string toHex(int num) {
			string s;
			unsigned int i;

			if(num == 0)
				return "0";
			else if(num>0)
				i = num;
			else
				i = UINT_MAX+num+1;

			while(i%16!=0 || i/16!=0){
				s.insert(0,tochar(i%16));
				i /= 16;
			}
			return s;
		}
};

int main(int argc, char* argv[])
{
	Solution s;
	cout << s.tochar(10) << endl;
	cout << s.tochar(11) << endl;
	cout << s.tochar(8) << endl;
	cout << s.toHex(26) << endl;
	cout << s.toHex(-1) << endl;
	cout << UINT_MAX << endl;
	return 0;
}




