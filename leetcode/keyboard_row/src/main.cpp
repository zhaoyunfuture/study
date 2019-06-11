#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int map[26] = {2,3,3,2,1,2,2,2,1,2,2,2,
            3,3,1,1,1,1,2,1,1,3,1,3,1,3};
        vector<string> r;
        bool sameRow = true;
        if(words.size()==0)
            return words;
        for(int k=0;k<words.size();++k){
            string s = words.at(k);
            for ( string::iterator i = s.begin(); i != s.end(); ++i )
            {
                *i = toupper( *i );
            }
            int j = map[*(s.begin())-'A'];
            sameRow = true;
            for ( string::iterator i = s.begin(); i != s.end(); ++i )
            {
                if(j != map[*i-'A']){
                    sameRow = false;
                    break;
                }                    
            }
            if(sameRow)
                r.push_back(words.at(k));
        }
        return r;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




