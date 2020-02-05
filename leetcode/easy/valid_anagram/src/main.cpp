#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> m;
        map<char,int>::iterator mit;
        for ( string::iterator sit=s.begin(); sit!=s.end(); ++sit) {
            mit = m.find(*sit);
            if(mit == m.end())
                m.insert(pair<char,int>(*sit,1));
            else
                mit->second += 1;
        }
        for ( string::iterator tit=t.begin(); tit!=t.end(); ++tit) {
            mit = m.find(*tit);
            if(mit == m.end())
                return false;
            else {
                mit->second -= 1;
                if(mit->second == 0)
                    m.erase(mit);
            }
        }
        if(m.size()==0)
            return true;
        else
            return false;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




