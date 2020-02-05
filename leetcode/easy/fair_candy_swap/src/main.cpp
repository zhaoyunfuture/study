#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
	public:
		vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
			set<int> s;
			set<int>::iterator sit;
			int sum_a=0;
			int sum_b=0;
			for(int i=0;i<A.size();i++){
				sum_a +=A.at(i);
				sit = s.find(A.at(i));
				if(sit == s.end())
					s.insert(A.at(i));
			}
			for(int i=0;i<B.size();i++){
				sum_b +=B.at(i);
			}
			vector<int> res;
			res.push_back(0);
			res.push_back(0);
			int half = (sum_a+sum_b)/2;

			for(int i=0;i<B.size();i++){
				int t = sum_b - B.at(i);
				if(t<half){
					if(s.find(half-t)!=s.end()){
						res.at(0) = half-t;
						res.at(1) = B.at(i);
						break;
					}
				}else
					continue;
			}
			return res;
		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




