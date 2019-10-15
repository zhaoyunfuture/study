#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
	public:
		int maxDistToClosest(vector<int>& seats) {
			int size = seats.size();
			if(size<3)
				return 1;

			int left=0;
			int leftIndex=0;
			int right=0;
			int rightIndex=0;
			if(seats.at(0)==0){
				left++;
				while(seats.at(left)!=1)
					left++;
			}
			leftIndex = left==0?0:left-1;
			int i=size-1;
			if(seats.at(size-1)==0){
				right++;
				i--;
				while(i>0 && seats.at(i)!=1){
					right++;
					i--;
				}
			}
			rightIndex = i;     

			if(rightIndex-leftIndex<4){
				if(left==right && left==0)
					return 1;
				else
					return left>right?left:right;
			}
			else{
				int mid=0;
				int t=0;
				for(int j=leftIndex+1;j<=rightIndex;j++){
					if(seats.at(j)==0){
						t++;
					}else{
						if(t>mid)
							mid = t;
						t = 0;
					}
				}            

				int m = (mid+1)/2;
				return left>right?(left>m?left:m):(right>m?right:m);
			}
		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




