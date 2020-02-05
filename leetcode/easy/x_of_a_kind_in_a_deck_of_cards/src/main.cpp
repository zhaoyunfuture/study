#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int len = deck.size();
        if(len==1)
            return false;
        map<int,int> m;
        map<int,int>::iterator mit;
        for(int i=0;i<len;i++){
            mit = m.find(deck.at(i));
            if(mit == m.end()){
                m.insert(pair<int,int>(deck.at(i),1));
            }else{
                mit->second++;
            }
        }
        if(m.size()==1)
            return true;
        bool single = false;
        bool even = false;
        bool odd = false;
        for(mit = m.begin();mit!=m.end();mit++){
            if(mit->second == 1) {
                single = true;
                break;
            }
            if(mit->second % 2 == 0)
                even = true;
            else
                odd = true;
        }
        if(single)
            return false;
        if(even&&odd)
            return false;
        return true;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




