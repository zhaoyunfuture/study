#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        if(p.size()==0||s.size()==0)
            return v;

        map<char,int> m;
        map<char,int> t;
        map<char,int>::iterator mit;
        for(int i=0;i<p.size();++i) {
            mit = m.find(p.at(i));
            if(mit==m.end())
                m.insert(pair<char,int>(p.at(i),1));
            else
                mit->second +=1;
        }
        int b = s.size()-p.size();
        for(int j=0;j<=b;++j) {
            for(int k=i;k<i+p.size();++k){

            }
        }

    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




