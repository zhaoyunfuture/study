#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
    public:
        bool canrm(string& s){
            string res;
            int len = s.length();
            if(len==0||len==1)
                return false;
            for(int i=1;i<len;i++){
                if(s.at(i-1)==s.at(i)){
                    s.erase(i-1,2);
                    return true;
                }
            }
            return false;
        }
        string removeDuplicates(string S) {
            while(canrm(S)){
            }
            return S;
        }
};
int main(int argc, char* argv[])
{
  
	return 0;
}




