#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool match(char s, char p,char lastletter){
        if(p == '.')
            return true;
        if(p == s)
            return true;
        if(p=='*'&& '.' == lastletter)
            return true;
        if(p=='*'&& s == lastletter)
            return true;
        return false;
    }
    bool isMatch(string s, string p) {
        int len_s = s.length();
        int len_p = p.length();        
        if(len_s == 0 || len_p == 0)
            return false;        
        char lastletter= ' ';
        int j=0;
        int i=0;
        for(;i<s.length();){
            if(p.at(j)!='*')
		lastletter = p.at(j);
            while(!match(s.at(i),p.at(j),lastletter)){
                j++;                    
                if(j==p.length())
                    return false;
                if(p.at(j)!='*')
                    lastletter = p.at(j);
            }
            j++;
	    i++;
            if(j==p.length())
                break;            
        }
        if(j!=p.length()||i!=s.length())
            return false;
        else
            return true;
    }
};

int main(int argc, char* argv[])
{
    Solution ss;
    string s = "aaa";
    string p = "ab*a*c*a";
    bool out = false;
    out = ss.isMatch(s,p);
    cout << out << endl;
	return 0;
}




