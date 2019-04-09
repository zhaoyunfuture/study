#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        v = nums;
    }

    int sumRange(int i, int j) {
        int sum = 0;
        if(j>v.size())
            return 0;
        for(int k =i;k<=j;++k)
            sum +=v.at(k);
        return sum;
    }
private:
    vector<int> v;
};

/**
 *  * Your NumArray object will be instantiated and called as such:
 *   * NumArray* obj = new NumArray(nums);
 *    * int param_1 = obj->sumRange(i,j);
 *     */

int main(int argc, char* argv[])
{
  
	return 0;
}




