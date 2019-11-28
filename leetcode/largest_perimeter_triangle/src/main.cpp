#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    struct myclass {
        bool operator() (int i,int j) { return (i>j);}
    } myobject;
    bool maxPm(int i,int& max,vector<int>& A){
        if(A.at(i)>=(A.at(i+1)+A.at(i+2)))
            return false;
        else{
            max = A.at(i)+A.at(i+1)+A.at(i+2);
            return true;
        }
    }
    int largestPerimeter(vector<int>& A) {
        int max=0;
        sort (A.begin(), A.end(), myobject);    
        for(int i=0;i<A.size()-2;i++){
            if(maxPm(i,max,A))
                break;
        }
        return max;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




