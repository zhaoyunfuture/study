#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool valid(string s,bool cutone){
        int len = s.length();
        int i = 0;
        int j = len-1;
        for(;i<j;i++,j--){
            if(s.at(i)!=s.at(j)){
                if(cutone)
                    return false;
                string s1 = s;
                s.erase(s.begin()+i);
                s1.erase(s1.begin()+j);
                return valid(s,true) || valid(s1,true);
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        return valid(s,false);
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




