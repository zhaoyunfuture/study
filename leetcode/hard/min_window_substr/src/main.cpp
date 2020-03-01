#include <string.h>
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution {
    public:   
        bool containall(map<char,int>& sm,map<char,int>& m){   
            map<char,int>::iterator mit;
            map<char,int>::iterator smit;
            for(mit=m.begin();mit!=m.end();mit++){
	        smit = sm.find(mit->first);
	        if(smit==sm.end())
	            return false;
	        else{
	            if(mit->second>smit->second)
	                return false;
	        }
	    }
            return true;   
        }
        void load(map<char,int>& sm,string s,int len){
            map<char,int>::iterator mit;
            for(int i=0;i<len;i++){
                mit = sm.find(s.at(i));
                if(mit==sm.end()){
                    sm.insert(pair<char,int>(s.at(i),1));
                }else{
                    mit->second++;

                }

            }

        }
        string minWindow(string s, string t) {
            string out="";
            int t_len = t.length();
            int s_len = s.length();
            map<char,int> m;
            map<char,int> sm;
            map<char,int>::iterator mit;
            for(int i=0;i<t_len;i++){
                mit = m.find(t.at(i));
                if(mit==m.end()){
                    m.insert(pair<char,int>(t.at(i),1));

                }else{
                    mit->second++;

                }

            }

            for(int j=t_len;j<=s_len;j++){
                sm.clear();
                load(sm,s,j);
                if(containall(sm,m))
                    return s.substr(0,j);
                for(int i=1;i<=s_len-j;i++){
                    mit = sm.find(s.at(i-1));
                    mit->second--;
                    if(mit->second==0)
                        sm.erase(s.at(i-1));
                    mit = sm.find(s.at(i+j-1));
                    if(mit == sm.end())                  
                        sm.insert(pair<char,int>(s.at(i+j-1),1));
                    else
                        mit->second++;

                    if(containall(sm,m))
                        return s.substr(i,j);

                }

            }        
            return out;

        }

};

int main(int argc, char* argv[])
{
    Solution ss;
    string s= "ADOBECODEBANC";
    string t= "ABC";
    cout << ss.minWindow(s,t);
	return 0;
}




