#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
	public:
		void Lower( std::string&  str )
		{
			for ( std::string::iterator i = str.begin(); i != str.end(); ++i )
			{
				*i =  tolower(*i);
				if(isdigit(*i))
					continue;
				if(!isalpha(*i))
				{
					str.erase(i);
					i--;
				}
			}
		}

		bool isPalindrome(string s) {
			if(s == "")
				return true;
			string ss=s;
			Lower(ss);
			cout << ss << endl;
			int size = ss.size();
			cout << size << endl;
			std::string::iterator i=ss.begin();
			std::string::reverse_iterator rit=ss.rbegin();
			for(int pos = 0;pos < size/2;++i,++rit,++pos)
			{
				if(*i != *rit)
				{
					return false;
				}
			}
			return true;
		}
};

int main(int argc, char* argv[])
{
    Solution s;
	//string str= "A man ,  a plan, a canal: Panama";
	string str= "0P";
	bool t = s.isPalindrome(str);
	cout << "t " << t << endl;
	return 0;
}




