#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
	public:
		vector<int> numberOfLines(vector<int>& widths, string S) {
			vector<int> v;
			int line = 1;
			int t = 0;
			int l = 0;
			for(int i=0;i<S.size();++i) {
				t = widths.at(S.at(i)-'a');
				if(l+t>100){
					line++;
					l = t;
				}else{
					l += t;
				}
			}
			v.push_back(line);
			v.push_back(l);
			return v;
		}
};
int main(int argc, char* argv[])
{
  
	return 0;
}




