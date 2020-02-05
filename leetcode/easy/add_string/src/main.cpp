#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
	public:
		string add(char a,char b,bool& income) {
			int r;
			string s;

			if(income)
				r = a+b+1-'0'-'0';
			else
				r = a+b-'0'-'0';

			if(r>9){
				income = true;
				s = to_string(r-10);
				return s;
			}else {
				income = false;
				return to_string(r);
			}
		}
		string addStrings(string num1, string num2) {
			if(num1.size()==0||num2.size()==0){
				if(num1.size()==0)
					return num2;
				else
					return num1;
			} 
			bool i = false;
			string::reverse_iterator rit1=num1.rbegin();
			string::reverse_iterator rit2=num2.rbegin();
			string r;
			string one="1";
			while(rit1!=num1.rend() || rit2!=num2.rend()){
				if(rit1==num1.rend()){
					r.insert(0,add('0',*rit2,i));
					rit2++;
				}else if(rit2==num2.rend()) {
					r.insert(0,add('0',*rit1,i));
					rit1++;
				}else{
					r.insert(0,add(*rit1,*rit2,i));
					rit1++;
					rit2++;
				}                
			}
			if(i)
				r.insert(0,one);
			return r;
		}
};
int main(int argc, char* argv[])
{
	Solution s;
	string r;
	r = s.addStrings("9","1");
	cout << r << endl;
	return 0;
}

