#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int orignalR = nums.size();
        int orignalC = nums.at(0).size();
        if(orignalR*orignalC != r*c)
            return nums;
        vector<vector<int>> res;
        vector<int> t;
        int index=0;
        for(int i=0;i<orignalR;++i) {
            for(int j=0;j<orignalC;++j) {
                t.push_back(nums.at(i).at(j));
                index++;
                if(index==c){
                    res.push_back(t);
                    t.clear();
                    index = 0;
                }
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




