#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
	public:
		void reverse(string& s, int first, int end) {
			int f = first;
			int e = end;
			char t;
			while(f<e){
				t = s.at(f);
				s.at(f) = s.at(e);
				s.at(e) = t;
				f++;
				e--;
			}
		}
		string reverseWords(string s) {
			if(s.length()==0)
				return s;
			std::size_t pos;
			std::size_t lastpos;
			lastpos=s.find(' ');
			if(lastpos!=std::string::npos){
				reverse(s,0,lastpos-1);
			}else{
				reverse(s,0,s.length()-1);
				return s;
			}
			pos = s.find(' ',lastpos+1);
			while (pos!=std::string::npos) {
				reverse(s,lastpos+1,pos-1);
				lastpos = pos;
				pos = s.find(' ',lastpos+1);
			}
			if(lastpos<s.length()){
				reverse(s,lastpos+1,s.length()-1);
			}
			return s;


		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




