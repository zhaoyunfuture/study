#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
    public:
        typedef struct{
            int num;
            int cont;

        } m_data;
        bool match(string s,int swl,int size,map<string,m_data> m){
            map<string,m_data>::iterator mit;
            for(int i=0;i<size;i++){
                string sub = s.substr(i*swl,swl);
                mit = m.find(sub);
                if(mit==m.end())
                    return false;
                else{
                    mit->second.cont++;

                }

            }
            for(mit=m.begin();mit!=m.end();mit++){
                if(mit->second.num != mit->second.cont)
                    return false;

            }
            return true;        

        }
        vector<int> findSubstring(string s, vector<string>& words) {
            vector<int> v;
            int size = words.size();
            if( size == 0 )
                return v;
            int swl = words.at(0).length();        
            int wLen = size*swl;
            int sLen = s.length();
            if(sLen < wLen || sLen==0 )
                return v;
            map<string,m_data> m;
            map<string,m_data>::iterator mit;
            for(int i=0;i<words.size();i++){
                mit = m.find(words.at(i));
                if(mit==m.end()){
                    m_data md;
                    md.num = 1;
                    md.cont = 0;
                    m.insert(pair<string,m_data>(words.at(i),md));

                }else
                    mit->second.num++;

            }
            for(int i=0;i<=sLen-wLen;i++){
                string sub = s.substr(i,wLen);
                if(match(sub,swl,size,m))
                    v.push_back(i);            

            }
            return v;

        }

};

int main(int argc, char* argv[])
{
  
	return 0;
}




