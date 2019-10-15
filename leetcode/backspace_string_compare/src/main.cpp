#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string proc(string s) {
        string o;
        int num=0;
        for(int i=s.length()-1;i>=0;i--){            
            if(s.at(i) == '#'){
                num++;
                continue;
            }
            if(num){
                num--;
                continue;
            }
            if(o.length()==0)
                o.push_back(s.at(i));
            else
                o.insert(o.begin(),s.at(i));
        }
        return o;
    }
    bool backspaceCompare(string S, string T) {
        string s;
        string t;
        s = proc(S);
        t = proc(T);
        cout <<s << " " << t;
        if(s==t)
            return true;
        else
            return false;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




