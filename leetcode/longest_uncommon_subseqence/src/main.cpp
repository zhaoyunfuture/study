#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
	public:
		bool isSame(string a,string b) {
			for(int i=0;i<a.length();++i) {
				if(a.at(i)!=b.at(i))
					return false;
			}
			return true;
		}
		bool findSame(string a,string b) {
			int lena = a.length();
			int lenb = b.length();
			string t;
			for(int i=0;i<=(lenb-lena);++i) {
				t = b.substr(i,lena);
				if(isSame(a,t))
					return true;
			}
			return false;

		}
		int findLUSlength(string a, string b) {
			int lena = a.length();
			int lenb = b.length();
			string s;
			string l;
			if(lena==0 &&lenb==0)
				return -1;
			if(lena==0 ||lenb==0)
				return lena==0?lenb:lena;
			if(lena>lenb){
				l = a;
				s = b;
			}else {
				l = b;
				s = a;
			}
			if(findSame(s,l))
				return -1;
			else
				return lena>lenb?lena:lenb;

		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




