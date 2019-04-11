#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.size();
        if(size == 0)
            return -1;
        vector<int> v(size);
        map<char,int> m;
        map<char,int>::iterator mit;
        for(int i=0;i<size;++i) {
            mit = m.find(s.at(i));
            if(mit == m.end()) {
                m.insert(pair<char,int>(s.at(i),i));
            }else {
                v.at(mit->second) = 1;
                v.at(i) = 1;
            }
        }
        for(int j=0;j<size;++j) {
            if(v.at(j)==0)
                return j;
        }
        return -1;        
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




