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
        map<char,int>::iterator tit;
        for(int i=0;i<p.size();++i) {
            mit = m.find(p.at(i));
            if(mit==m.end())
                m.insert(pair<char,int>(p.at(i),1));
            else
                mit->second +=1;
        }
        bool find = true;
        bool finalfind = true;
        int b = s.size()-p.size();
        for(int j=0;j<=b;++j) {
            t.clear();
            find = true;
            for(int k=j;k<j+p.size();++k){
                mit = m.find(s.at(k));
                if(mit == m.end()){
                    find = false;
                    break;
                }else{
                    tit = t.find(s.at(k));
                    if(tit == t.end())
                        t.insert(pair<char,int>(s.at(k),1));
                    else
                        tit->second +=1;
                }
            }
            finalfind = true;
            if(find){
                for(tit=t.begin();tit!=t.end();++tit){
                    mit = m.find(tit->first);
                    if(mit->second != tit->second){
                        cout << "cont not same" << endl;
                        finalfind = false;
                        break;
                    }                        
                }
                if(finalfind)
                    v.push_back(j);
            }                
        }
        return v;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




