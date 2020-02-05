#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        string out;
        int index=0;
        for(int i=0;i<S.length();i++){
            if(index==0){
                if(S.at(i)=='('){
                    index++;
                }
            }else if(index == 1){
                if(S.at(i)==')'){
                    index--;
                }else{
                    index++;
                    out.push_back('(');
                }
            }else{
                if(S.at(i)=='('){
                    index++;
                    out.push_back('(');
                }else{
                    index--;
                    out.push_back(')');
                }
            } 
        }
        return out;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




