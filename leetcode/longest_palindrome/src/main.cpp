#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size()<2)
            return s.size();
        map<char,int> m;
        map<char,int>::iterator mit;
        bool single = false;
        int len = 0;
        for(int i=0;i<s.size();++i) {
            mit = m.find(s.at(i));
            if(mit == m.end()){
                m.insert(pair<char,int>(s.at(i),1));
            }else {
                mit->second += 1;
            }
        }
        for(mit=m.begin();mit!=m.end();++mit){
            if(mit->second%2 != 0){
                single = true;
                len += mit->second - 1;
            }else
                len += mit->second;
        }
        return single? len+1:len; 
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




