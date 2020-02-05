#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int find(int l, int h, int target,vector<int>& nums){
        int low = l;
        int high = h;
        int mid = (low+high)/2;
        if(mid == low)
        {
            if(target <= nums.at(mid))
                return mid;
            else if(target > nums.at(mid) && target < nums.at(high))
                return mid+1; 
            else if(target == nums.at(high))
                return high;
            else 
                return high+1;

        }
        if(target > nums.at(mid))
        {
            low = mid + 1;
            return find(low,high,target,nums);
        }
        else if(target < nums.at(mid))
        {
            high = mid - 1;
            return find(low,high,target,nums);
        }
        else
        {
            return mid;
        }

    }
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        
        return find(low,high,target,nums);
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> n;
    n.push_back(1);
    n.push_back(2);
    n.push_back(5);
    n.push_back(7);
    n.push_back(8);
    cout << s.searchInsert(n,3) << endl;
    cout << s.searchInsert(n,6) << endl;
    cout << s.searchInsert(n,1) << endl;
    cout << s.searchInsert(n,9) << endl;
	return 0;
}


