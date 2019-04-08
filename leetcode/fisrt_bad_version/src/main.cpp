#include <string.h>
#include <string>
#include <iostream>
using namespace std;
bool isBadVersion(int version);

class Solution {
public:
    int find(int mi,int ma) {
        int min = mi;
        int max = ma;
        int mid = min+(max-min)/2;
        if(min == mid)
            return max;
        if(isBadVersion(mid))
            max = mid;
        else
            min = mid;
        return find(min,max);
    }
    int firstBadVersion(int n) {
        if(isBadVersion(1))
            return 1;
        return find(1,n);
    }
};
int main(int argc, char* argv[])
{
  
	return 0;
}




