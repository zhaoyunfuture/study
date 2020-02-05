#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:    
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> v;
        int len = A.size();
        int val = A.at(0);
        if(val%5==0)
            v.push_back(true);
        else
            v.push_back(false);

        if(len==1)
            return v;
        else{
            for(int i=1;i<len;i++){
                val = val*2+A.at(i);
                val %= 10;
                if(val%5==0)
                    v.push_back(true);
                else
                    v.push_back(false);
            }
        }
        return v;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




