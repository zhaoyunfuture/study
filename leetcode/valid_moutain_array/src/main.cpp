#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int len=A.size();
        if(len<3)
            return false;
        int v = A.at(0);
        if(v >= A.at(1))
            return false;

        bool dec = false;
        for(int i=1;i<len;i++){
            if(v<A.at(i)){
                if(dec)
                    return false;
                else
                    v = A.at(i);
            }
            else if(v==A.at(i))
                return false;
            else{
                dec = true;
                v = A.at(i);
            }
        }
        if(dec)
            return true;
        else
            return false;
    }
};
int main(int argc, char* argv[])
{
  
	return 0;
}




