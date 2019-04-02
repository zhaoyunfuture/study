#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        int con = 0;
        bool flag = true;
        if(n <= 2)
            return 0;        
        else if (n==3)
            return 1;        
        else {
            for(int i=4;i<n;++i) {
                flag = true;
                for(int j=2;j<=i/2;++j) {
                    if(i%j == 0) {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    con++;
            }
        }
        return con+2;
    }
};
int main(int argc, char* argv[])
{
    Solution s;
    cout << s.countPrimes(15) << endl;
    cout << s.countPrimes(5) << endl;
    cout << s.countPrimes(499979) << endl;
	return 0;
}




