#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool find(string &s, int index) {
        char first = s.at(index);
        int firstCont = 1;
        int secCont = 0;
        bool flip = false;
        for(int i=index+1;i<s.length();++i){
            if(!flip && s.at(i) == first){
                firstCont ++;
            }else if(!flip && s.at(i) != first){
                flip = true;
                secCont++;
                if(firstCont == secCont)
                    return true;
            }else if(flip && s.at(i) != first) {
                secCont++;
                if(firstCont == secCont)
                    return true;
            }else {
                break;
            }        
        }
        if(firstCont == secCont)
            return true;
        else
            return false;
    }
    int countBinarySubstrings(string s) {
        int len=s.length();
        if(len == 1)
            return 0;
        int cont = 0;
        for(int i=0;i<len-1;++i){
            if(find(s,i))
                cont++;
        }
        return cont;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




