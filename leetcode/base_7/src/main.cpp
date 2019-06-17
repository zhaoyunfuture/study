#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        bool ispositive = true;
        if(num < 0) {
            ispositive = false;
            num = -num;
        }
        int mod = num%7;
        string r;
        string t;
        if(num == 0)
            return to_string(0);
        num /= 7; 
        while(mod!=0 || num!=0){
            t = to_string(mod);
            printf("%s ", t.c_str());
            r.insert(0,t);
            mod = num%7;
            num /= 7;
        }
        if(ispositive)
            return r;
        else {
            r.insert(0,"-");
            return r;
        }
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    cout << s.convertToBase7(1) << endl;;
	return 0;
}




