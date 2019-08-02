#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
	public:
		struct mapcomp {
			bool operator() (const int& lhs, const int& rhs) const
			{return lhs<rhs;}
		};
		int findLHS(vector<int>& nums) {
			map<int,int,mapcomp> m;
			map<int,int,mapcomp>::iterator mit;
			map<int,int,mapcomp>::iterator mit1;
			int size = nums.size();
			if(size == 0)
				return 0;
			int t;
			for(int i=0;i<size;++i) {
			    t = nums.at(i);
				mit = m.find(t);

				if(mit == m.end()) {
					m.insert(pair<int,int>(t,1));
				}
				else{
					cout << mit->first <<" "<< mit->second <<" " <<t<<endl;
                    mit->second++;
				}
			}
			int max = 0;
			mit=m.begin();
			mit1 = ++mit;
			mit=m.begin();
			for(;mit1!=m.end();) {
				if(mit1->first-mit->first == 1){
					if(mit1->second+mit->second > max){
						max = mit1->second+mit->second;
						cout << mit->first << " " << mit->second << endl;
						cout << mit1->first << " " << mit1->second << endl;
					}
				}
				mit++;
				mit1++;
			}
			return max;
		}
};

int main(int argc, char* argv[])
{
	Solution s;
	int myint[] = {6284,2052,4671,7951,8299,4321,9980,9495,-8844,9634,7087,2707,1527,9889,4452,7149,2654,-2848,-8766,9700,2262,8111,2233,6734,-8715,9838,5685,5564,4896,-6429,2047,-3720,9,7813,5169,2152,-6319,-7131,-9838,6080,4319,1789,1717,2991,-3474,3536,-4327,1484,2782,5384,5063,2888,5344,8280,4758,3287,5395,-5620,9745,2374,2344,-5749,7750,5945,4976,-5311,9009,9486,-970,2191,-6896,7781,9284,3504,5055,266,8206,8196,9346,6964,4582,4298,6918,6448,2149,6542,4093,8479,3564,518,6917,2905,6444,2592,3644,3626,4906,3394,4351,1281,8009,2874,-4299,7068,1575,8846,8418,2212,8674,5150,2864,8031};
	vector<int> v (myint, myint + sizeof(myint) / sizeof(int) );
	cout << s.findLHS(v);
	
	return 0;
}




