#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (vector<int>::iterator it = nums.begin() ; it != nums.end(); ++it){
            if(*it == 0){
                nums.erase(it);
                i++;     
                it--;
            }

        }
        for(;i>0;i--){
            nums.push_back(0);
        }
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




