#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isGood(int n) {
        int t = n;
        bool onlyself = true;
        while(t%10!=0 || t!=0) {
            if(t%10 == 3|| t%10 == 4||t%10 == 7)
                return false;
            else if(t%10 == 2 ||t%10 == 5||t%10 == 6||t%10 == 9)
                onlyself = false;
            t /= 10;
        }
        if(onlyself)
            return false;
        else
            return true;
    }
    int rotatedDigits(int N) {
        int num=0;
        for(int i=1;i<=N;i++){
            if(isGood(i))
                num++;
        }
        return num;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




