#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool divisorGame(int N) {
        if(N==1)
            return false;
        if(N==2)
            return true;
        bool canwin=true;
        for(int i=1;i<N;i++){
            if(i==1){
                if(N%2==0)
                    canwin = false;
            }else{
                if(N%i==0)
                    canwin = canwin && divisorGame(N-i);
            }
            if(canwin==false)
                break;
        }
        if(canwin==false)
            return true;
        else
            return false;
    }
};
;
int main(int argc, char* argv[])
{
    Solution s;
    for(int i=7;i>1;i--)
        cout << s.divisorGame(i) << endl;
    cout << s.divisorGame(100) << endl;
	return 0;
}




