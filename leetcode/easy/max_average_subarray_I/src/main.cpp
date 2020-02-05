#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxsub = 0;
        double last = 0;
        for(int i=0;i<k;++i) {
            maxsub += nums.at(i);
        }
        last = maxsub;
        for(int j=k;j<nums.size();++j) {
            last = last-nums.at(j-k)+nums.at(j);            
            if(last>maxsub)
                maxsub = last;
        }       
        return maxsub/k;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




