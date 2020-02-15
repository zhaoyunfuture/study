#include <string.h>
#include <string>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    struct comp {
      bool operator() (const int& lhs, const int& rhs) const
      {return lhs>rhs;}
    };
    int matchPair(string s){
        int c=0;
        int i=0;
        int p=0;
        int total = 0;
        for(;i<s.length();i++){
            if(s.at(i)=='(')
                c += 1;
            else{
                c -= 1;
                p += 1;
                if(c==0){
                    total += p;
                    p = 0;                    
                }                    
            }
            if(c<0)
                break;
        }        
        return total*2;
    }
    int longestValidParentheses(string s) {
        int len = s.length();
        if(len<2)
            return 0;
        set<int,comp> ms;
        set<int,comp>::iterator sit;
        for(int i=0;i<len-1;i++){
            if(s.at(i)==')')
                continue;
            ms.insert(matchPair(s.substr(i,len-i)));
        }
        sit = ms.begin();
        return (*sit);
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    string ss = "(()";
    int i=0;
    i = s.longestValidParentheses(ss);
    cout << i << endl;
	return 0;
}




