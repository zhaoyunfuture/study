#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
	public:
		void reverse(string& s,int k, int index) {
			int h = index;
			int t = index+k-1;
			char c;
			while(h<t) {
				c = s.at(h);
				s.at(h) = s.at(t);
				s.at(t) = c;
				h++;
				t--;
			}
		}
		string reverseStr(string s, int k) {
			int num = s.length()/(2*k);
			int mod = s.length()%(2*k);
			if(num==0 && mod<k) {
				reverse(s,mod,0);
				return s;
			}
			for(int i=0;i<num;++i) {
				reverse(s,k,i*2*k);
			}
			if(mod==0)
				return s;
			else if(mod<k) {
				reverse(s,mod,2*k*num);
				return s;
			}else {
				reverse(s,k,2*k*num);
				return s;
			}
		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




