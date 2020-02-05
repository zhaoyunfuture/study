#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        if(s.size()==0)
            return 0;
        bool aword = false;
        int k=0;
        for(int i=0;i<s.size();++i){
            if(s.at(i)!=' ' && !aword){
                k++;
                aword = true;
            }else if(s.at(i)==' '){
                aword = false;
            }
        }
        return k;

    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




