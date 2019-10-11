#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> v;
        vector<int> t;
        int len = S.length();
        if(len < 3)
            return v;
        char c = S.at(0);
        int num = 1;
        int first = 0;
        for(int i=1;i<len;++i){
            if(c == S.at(i)){
                num++;
                if(num>2 && i+1==len){
                    t.clear();
                    t.push_back(first);
                    t.push_back(i);                   
                    v.push_back(t);
                }
            }else{
                if(num>2){
                    t.clear();
                    t.push_back(first);
                    t.push_back(i-1);                   
                    v.push_back(t);
                }
                num = 1;
                first = i;
                c = S.at(i);
            }
        }
        return v;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




