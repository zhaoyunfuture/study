#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> m;
        map<char,int>::iterator mit;
        for(int i=0;i<t.size();++i) {
            mit = m.find(t.at(i));
            if(mit == m.end())
                m.insert(pair<char,int>(t.at(i),1));
            else
                mit->second +=1;
        }
        for(int j=0;j<s.size();++j) {
            mit = m.find(s.at(j));
            if(mit == m.end())
                printf("error: should not happen");
            else {
                mit->second -=1;
                if(mit->second == 0)
                    m.erase(mit);
            }
        }        
        return m.begin()->first;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




