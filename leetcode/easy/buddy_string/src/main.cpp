#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        int lenA = A.length();
        int lenB = B.length();
        if(lenA != lenB)
            return false;
        bool hasSameLetter = false;
        int diffNum = 0;
        char tmp[4];
        set<char> s;
        set<char>::iterator sit;
        for(int i=0;i<A.length();i++){
            if(A.at(i) == B.at(i)){
                sit = s.find(A.at(i));
                if(sit == s.end())
                    s.insert(A.at(i));
                else
                    hasSameLetter = true;
            }else{
                if(diffNum == 0){
                    tmp[0] = A.at(i);
                    tmp[1] = B.at(i);
                    diffNum++;
                }else if(diffNum == 1){
                    tmp[2] = A.at(i);
                    tmp[3] = B.at(i);
                    diffNum++;
                }else
                    diffNum++;                
            }
        }
        if(diffNum == 0){
            if(hasSameLetter)
                return true;
            else
                return false;
        }
        if(diffNum == 2){
            if(tmp[0]==tmp[3] && tmp[1]==tmp[2])
                return true;
            else
                return false;
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




