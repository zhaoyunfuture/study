#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string cns(string n)
    {
        string s;
        string c;
        string append;
        string nn;
        unsigned int i = 1;
        unsigned int count = 1;
        if(n.length() == 1)
        {
            s.append(std::to_string(1));
            s.append(n);
            return s;
        }
        while(i < n.length())
        {
            if(n.at(0) == n.at(i))
            {
                count++;
                i++;
            }
            else
            {
                nn.assign(n,i,n.length()-i);
                append = cns(nn);
        		break;
            }
        }
        s.append(std::to_string(count));
        c = n.at(0);
        s.append(c);
        s.append(append);
        return s;
    }

    string countAndSay(int n) {
        string s = "1";
        int c;
        if(n == 1)
            return s;
        else
        {
            for(c = n;c != 1;--c)
            {
                s = cns(s);
            }
        }
        return s;
    }
};

int main(int argc, char* argv[])
{   
    Solution s;
    string ss = "1";
    cout << s.cns(ss) << endl;;
    string sss = "11";
    cout << s.cns(sss) << endl;;
    string ssss = "21";
    cout << s.cns(ssss) << endl;
    cout << s.countAndSay(2) << endl;
    cout << s.countAndSay(3) << endl;
    cout << s.countAndSay(4) << endl;
	return 0;
}




