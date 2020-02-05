#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
    public:
        bool noZero(int n){
            int t = n;
            while(t%10!=0 && t!=0){
                t /= 10;
            }
            if(t!=0)
                return false;
            else
                return true;            
        }
        vector<int> getNoZeroIntegers(int n) {
            vector<int> v;
            for(int i=1;i<=n/2;i++){
                if(noZero(i)&&noZero(n-i)){
                    v.push_back(i);
                    v.push_back(n-i);
                    break;
                }
            }
            return v;
        }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




