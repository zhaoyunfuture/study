#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int size = A.size();
        if(size == 1)
            return 0;
        int min, max;
        if(A.at(0)>A.at(1)){
            min = A.at(1);
            max = A.at(0);
        }else{
            min = A.at(0);
            max = A.at(1);
        }
        if(size == 2){
            if((max-min)<=K*2)
                return 0;
            else
                return max-min-2*K;
        }
        for(int i=2;i<size;i++){
            if(A.at(i)>max)
                max = A.at(i);
            if(A.at(i)<min)
                min = A.at(i);
        }
        if((max-min)<=K*2)
            return 0;
        else
            return max-min-2*K;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




