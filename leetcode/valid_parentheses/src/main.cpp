#include <string.h>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		string o_brackets = "([{";
		string c_brackets = ")]}";
		std::stack<int> s_int;

		if(s == "")
			return true;
		if(c_brackets.find(*(s.begin())) != std::string::npos)
			return false;
		for ( std::string::iterator it=s.begin(); it!=s.end(); ++it)
		{
			std::size_t ofound = o_brackets.find(*it);
			if (ofound!=std::string::npos)
			{
				s_int.push(ofound);
				continue;
			}
			std::size_t cfound = c_brackets.find(*it);
			if (cfound!=std::string::npos)
			{
				if(s_int.size() == 0)
					return false;
				if(s_int.top() == cfound)
				{
					s_int.pop();
					continue;
				}
				else
				{
					return false;
				}
			}
		}
		if(s_int.size() == 0)
			return true;
		else
			return false;
	}
};

int main(int argc, char* argv[])
{
	Solution s;
	cout << s.isValid("()") << endl;
	cout << s.isValid("()[]{}") << endl;
	cout << s.isValid("([])") << endl;
	cout << s.isValid("([)]") << endl;
    return 0;
}




