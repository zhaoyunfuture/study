#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
	public:
		vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
			int size1 = list1.size();
			int size2 = list2.size();
			int max = size1+size2-1;

			vector<string> v;
			for(int i=0; i<size1;++i) {
				for(int j=0;j<size2;++j) {
					if(list1.at(i) == list2.at(j)) {
						if( max>(i+j) ){
							v.clear();
							max = i+j;                        
							v.push_back(list1.at(i));
						}else if(max == (i+j))
							v.push_back(list1.at(i));
						else
							break;                        
					}                    
				}
			}
			return v;
		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




