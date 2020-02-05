#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isSelfDiv(int num) {
        int n = num;
        int d = 0;
        int size = 0;
        vector<int> digit;
        digit.clear();
        while(n != 0){
            d = n%10;
            if(d == 0)
                return false;
            else
                digit.push_back(d);
            n /= 10;
        }
        size = digit.size();
        for(int i=0;i<size;++i) {
            if(num%digit.at(i) != 0)
                return false;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        for(int i=left;i<=right;++i) {
            if(isSelfDiv(i))
                v.push_back(i);
        }
        return v;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




