#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum=0;
        int parts;
        for(int i=0;i<A.size();i++){
            sum += A.at(i);
        }
        if(sum%3!=0)
            return false;
        parts = sum/3;
        int break_time=0;
        sum=0;
        for(int i=0;i<A.size();i++){
            sum+=A.at(i);
            if(sum==parts){
                break_time++;
                sum=0;
                if(break_time==2)
                    break;
            }
        }

        if(break_time==2)
            return true;
        else
            return false;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




