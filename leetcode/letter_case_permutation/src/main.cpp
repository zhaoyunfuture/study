#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<int> letterindex;
        for(int i=0;i<S.size();i++){
            if(isdigit(S.at(i)))
                continue;
            else
                letterindex.push_back(i);
        }
        int lettersize = letterindex.size();
        vector<string> r;
        if(lettersize == 0){
            r.push_back(S);
            return r;
        }else{
            int con = 1<<lettersize;
            for(int i=0;i<con;i++){
                r.push_back(S);
            }
            for(int i=0;i<lettersize;i++){
                int mark = 1<<i;                
                int k=0;
                bool low = true;
                for(int j=0;j<con;j++){
                    if(low){
                        r.at(j).at(letterindex.at(i)) = tolower(r.at(j).at(letterindex.at(i)));
                    }else{
                        r.at(j).at(letterindex.at(i)) = toupper(r.at(j).at(letterindex.at(i)));
                    }
                    k++;
                    if(k == mark){
                        k = 0;
                        low = !low;
                    }
                }
            }
        }            
        return r;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




