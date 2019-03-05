#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        string t;
        if(s.length() == 0)
            return 0;
        std::size_t found = s.find_last_of(" ");
        if(found == s.length() -1)
        {
            std::size_t f = s.find_last_not_of(" ");
            if(f == 0)
                t = s.at(0);
            else
                t = s.substr(0,f+1);

            std::size_t f1 = t.find_last_of(" ");
            if(f1 == std::string::npos)
                return t.length();
            else
            {
                string r = t.substr(f1+1);
                return r.length();
            }

        }
        t = s.substr(found+1);
        return t.length();
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    //cout << s.lengthOfLastWord(" ") << endl;
//    cout << s.lengthOfLastWord("a ") << endl;
    cout << s.lengthOfLastWord(" a ") << endl;
    cout << s.lengthOfLastWord("  ") << endl;
    cout << s.lengthOfLastWord("hello world") << endl;
	return 0;
}




