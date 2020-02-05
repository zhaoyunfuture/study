#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
    public:
        struct myclass {
            bool operator() (int i,int j) { return (i<j); }

        } myobject;
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            nums1.insert(nums1.begin(),nums2.begin(),nums2.end());
            sort(nums1.begin(),nums1.end(),myobject);
            int len = nums1.size();

            double res=0;
            if(len%2==0){
                res = nums1.at(len/2)+nums1.at(len/2-1);
                res /= 2;

            }else{
                res = nums1.at(len/2);

            }
            return res;

        }

};

int main(int argc, char* argv[])
{
  
	return 0;
}




