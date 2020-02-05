#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool inc = false;
        bool dec = false;
        int len = A.size();
        if(len<3)
            return true;
        for(int i=1;i<len;i++){
            if(A.at(i)>A.at(i-1)) 
                inc = true;
            if(A.at(i)<A.at(i-1)) 
                dec = true;
            if(inc && dec)
                return false;
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




