#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
	public:
		bool checkPossibility(vector<int>& nums) {
			int cont = 0;
			int mark = 0;
			for(int i=0;i<nums.size()-1;++i) {
				if(nums.at(i)>nums.at(i+1)){
					cont++;
					mark = i;
				}
			}
			if(cont>1)
				return false;
			else if(cont == 1){
				if(mark == 0 || mark+2 == nums.size())
					return true;
				else {
					if(nums.at(mark-1)==nums.at(mark))
						nums.erase(nums.begin()+mark+1);
					else if(nums.at(mark+2)==nums.at(mark+1))
						nums.erase(nums.begin()+mark);
					else {
						if(nums.at(mark-1)<=nums.at(mark+1))
							nums.erase(nums.begin()+mark);
						else
							nums.erase(nums.begin()+mark+1);
					}

					for(int i=0;i<nums.size()-1;++i) {
						if(nums.at(i)>nums.at(i+1))
							return false;
					}
					return true;
				}
			}else
				return true;
		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




