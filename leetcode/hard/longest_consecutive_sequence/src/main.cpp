#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    struct myclass {
      bool operator() (int i,int j) { return (i<j);}
    } myobject;
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<2)
            return nums.size();
        sort (nums.begin(), nums.end(), myobject); 
        int cont=1;
        int out=1;
        int base=nums.at(0);
        for(int i=1;i<nums.size();i++){
            if(nums.at(i)==base+1){                
                cont++;
                if(cont>out)
                    out = cont;
            }else if(nums.at(i)==base){
                continue;
            }else{                
                cont=1;
            }
            base = nums.at(i);
        }
        return out;        
    }
};
int main(int argc, char* argv[])
{
  
	return 0;
}




