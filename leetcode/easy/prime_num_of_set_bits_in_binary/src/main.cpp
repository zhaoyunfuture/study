#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int setbit(int n){
        int c = n;
        int setbit = 0;
        while(c!=0){
            if(c%2!=0)
                setbit++;
            c /=2;
        }
        return setbit;
    }
    int countPrimeSetBits(int L, int R) {
        int prime[]= {2,3,5,7,11,13,17,19,23,29,31,37};
        set<int> p_set (prime,prime+12); 
        set<int>::iterator sit;
        int s;
        int count = 0;
        for(int i=L;i<=R;i++){
            s = setbit(i);
            sit = p_set.find(s);
            if(sit != p_set.end())
                count++;
        }
        return count;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




