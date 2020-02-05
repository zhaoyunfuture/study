#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool check(int dis,string &s){
        int len = s.length();
        char c;
        int k;
        bool same = true;
        for(int i=0;i<dis;++i) {
            c = s.at(i);
            k = i+dis;
            while(k<len){
                if(c != s.at(k)){
                    same = false;
                    break;
                }
                k += dis;
            }
            if(!same)
                break;            
        }
        return same;        
    }
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        if(len<2)
            return false;
        bool same = false;
        for(int i =1;i<=len/2;++i){
            if(len%i != 0)
                continue;
            if(check(i,s)){
                same = true;
                break;
            }                 
        }
        return same;

    }
};
int main(int argc, char* argv[])
{
  
	return 0;
}




