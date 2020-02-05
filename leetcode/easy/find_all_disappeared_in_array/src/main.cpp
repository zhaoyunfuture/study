#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> v;
        int size = nums.size();
        if(size == 0)
            return v;
        char t[size] = {0};
        for(int i=0;i<size;++i)
            t[nums.at(i)-1]=1;

        for(int j=0;j<size;++j){
            if(t[j]==0)
                v.push_back(j+1);
        }
        return v;            
    }
};
int main(int argc, char* argv[])
{
  
	return 0;
}




