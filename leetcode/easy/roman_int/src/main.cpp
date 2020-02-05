#include <string.h>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

class Solution {
public:
        int lookup(char& c, int& v){
            int level = 0;
            switch(c)
            {
                case 'I':
                    v = 1; level = 1;
                    break;
                case 'V':
                    v = 5; level = 2;
                    break;
                case 'X':
                    v = 10; level = 3;
                    break;
                case 'L':
                    v = 50; level = 4;
                    break;
                case 'C':
                    v = 100; level = 5;
                    break;
                case 'D':
                    v = 500; level = 6;
                    break;
                case 'M':
                    v = 1000; level = 7;
                    break;
                default:
                    v = 0; level = 0;
            }
            return level;
        }

        int romanToInt(string s) {
            int topLevel = 0;
            int curLevel = 0;
            int res = 0;
            int m = 0;
            string tmp = s;
            string::reverse_iterator rit = tmp.rbegin();
            
            for(;rit != tmp.rend();++rit)
            {
                curLevel = lookup(*rit,m);
                if(topLevel == 0)
                {
                    topLevel = curLevel;
                    res += m;
                    continue;
                }
                if(topLevel <= curLevel)
                {
                    topLevel = curLevel;
                    res += m;
                }
                if(topLevel > curLevel)
                    res -= m;

            }
            return res;
        }
};

int main(int argc, char* argv[])
{
    printf("hello \r\n");
    string ss = "III";
    Solution s;
    cout << s.romanToInt(ss) << endl;
    cout << s.romanToInt("MCMXCIV") << endl;
    return 0;
}
