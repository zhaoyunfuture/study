#include <string.h>
#include <string>
#include <set>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
	public:
		vector<int> powerfulIntegers(int x, int y, int bound) {
			set<int> s;
			set<int>::iterator sit;
			vector<int> v;
			int xi=0;
			int yi=0;
			int sum;
			int a=pow(x,xi);
			int b;
			while(a<bound){
				yi=0;
				b=pow(y,yi);
				sum = a+b;
				while(sum<=bound){
					s.insert(sum);
					if(y==1)
						break;
					yi++;
					b=pow(y,yi);
					sum=a+b;
				}
				if(x==1)
					break;
				xi++;
				a = pow(x,xi);
			}

			if(s.size()==0)
				return v;
			for(sit=s.begin();sit!=s.end();sit++){
				v.push_back(*sit);
			}
			return v;
		}
};

int main(int argc, char* argv[])
{
	Solution s;
	vector<int> v;
	v = s.powerfulIntegers(2,1,10);
	for(int i=0;i<v.size();i++)
	 cout << v.at(i);
	return 0;
}




