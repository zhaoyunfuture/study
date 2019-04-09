#include <string.h>
#include <string>
#include <iostream>
using namespace std;
#if 0 //option 1 : not so fast
class Solution {
public:
    bool canWinNim(int n) {
        if(n<4)
            return true;
        else if (n==4)
            return false;
        else {
            if(canWinNim(n-1)&&canWinNim(n-2)&&canWinNim(n-3))
                return false;
            else
                return true;
        }
    }
};
#endif
class Solution {
public:
    bool canWinNim(int n) {
            int i = n/4;
            if((n-4*i)==0)
                return false;
            else
                return true;
        }
};
int main(int argc, char* argv[])
{
    Solution s;
    cout << s.canWinNim(44) << endl;
    cout << s.canWinNim(4) << endl;
    cout << s.canWinNim(5) << endl;
    cout << s.canWinNim(6) << endl;
    cout << s.canWinNim(7) << endl;
    cout << s.canWinNim(8) << endl;
    cout << s.canWinNim(9) << endl;
    cout << s.canWinNim(10) << endl;
    cout << s.canWinNim(11) << endl;
    cout << s.canWinNim(12) << endl;
    cout << s.canWinNim(13) << endl;
	return 0;
}




