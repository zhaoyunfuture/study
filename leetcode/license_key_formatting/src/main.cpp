#include <string.h>
#include <string>
#include <iostream>
#include <ctype.h>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string s = S;
        std::size_t found = s.find("-");
        while(found != string::npos) {
            s.erase(s.begin()+found);
            found = s.find("-");
        }
        for ( string::iterator i = s.begin(); i != s.end(); ++i )
        {
            *i = toupper( *i );
        }
        int len = s.length();
        if(len <= K)
            return s;
        int dash_cont=0;
        int t = 1;
        if(len%K != 0){
            dash_cont = len/K;
            s.insert(len%K,"-");
            while(t!=dash_cont) {
                 s.insert(len%K+K*t+t,"-");
                 t++;
            }
        }
        else {
            dash_cont = len/K -1;
            s.insert(K,"-");
            while(t!=dash_cont) {
                s.insert(K*(t+1)+t,"-");
                t++;
            }
        }
        
        return s;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    cout << sol.licenseKeyFormatting("fa1-bc2-de3-fgh",3) << endl;
    cout << sol.licenseKeyFormatting("f",1) << endl;
	return 0;
}




