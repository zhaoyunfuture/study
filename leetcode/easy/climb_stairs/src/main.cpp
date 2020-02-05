#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int getClimbNum(int in)
    {
        if(in == 1)
            return 1;
        if(in == 2)
            return 2;

        int a = getClimbNum(in -1);
        int b = getClimbNum(in -2);
        return a+b;
    }
    int climbStairs(int n) {
        return getClimbNum(n);
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    cout << s.climbStairs(4) << endl;
    cout << s.climbStairs(5) << endl;
    cout << s.climbStairs(26) << endl;
	return 0;
}




