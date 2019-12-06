#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int count(string& s,char c){
        int num=0;
        for(int i=0;i<s.length();i++){
            if(c==s.at(i))
                num++;
        }
        return num;
    }
    void procstring(string s,map<char,vector<int>>& m){
        map<char,vector<int>>::iterator mit;
        string t = s;
        set<char> sc;
        set<char>::iterator sc_it;
        for(int i=0;i<s.length();i++){
            mit = m.find(s.at(i));
            if(mit != m.end()){
                sc_it = sc.find(s.at(i));
                if(sc_it == sc.end()){
                    int n = count(s,s.at(i));
                    if(n<mit->second.at(0))
                        mit->second.at(0) = n;
                    mit->second.at(1) += 1;
                    sc.insert(s.at(i));
                }
            }                
        }
    }
    vector<string> commonChars(vector<string>& A) {
        map<char,vector<int>> m;
        map<char,vector<int>>::iterator mit;
        vector<int> v;
        vector<string> sv;
        int size = A.size();
        for(int i=0;i<A.at(0).length();i++){
            mit = m.find(A.at(0).at(i));
            if(mit == m.end()){
                v.clear();
                v.push_back(1); /* char num */
                v.push_back(1); /* how many string has this char */
                m.insert(make_pair(A.at(0).at(i),v));
            }else{
                mit->second.at(0) += 1;
            }
        }
        if(size==1){
            for(mit=m.begin();mit!=m.end();mit++){
                int num = mit->second.at(0);
                for(int j=0;j<num;j++){
                    string s0;
                    s0.push_back(mit->first);                    
                    sv.push_back(s0);
                }
            }
            return sv;
        }
        for(int i=1;i<size;i++){
            procstring(A.at(i),m);
        }
        for(mit =m.begin();mit!=m.end();mit++){
            if(mit->second.at(1)==size){
                for(int i=0;i<mit->second.at(0);i++){
                    string s0;
                    s0.push_back(mit->first);   
                    sv.push_back(s0);
                }
            }
        }
        return sv;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




