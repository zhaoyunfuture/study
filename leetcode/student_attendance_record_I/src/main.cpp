#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
	public:
		bool checkRecord(string s) {
			int contA = 0;
			int contL = 0;
			bool iscontL = false;
			for(int i=0;i<s.length();++i) {
				if(s.at(i) == 'A'){ 
					contA++;
					contL = 0;
				}
				else if(s.at(i) == 'L'){ 
					contL++;
					if(contL>2)
						iscontL = true;
				}else
					contL = 0;
			}
			if(contA>1 || iscontL)
				return false;
			else
				return true;
		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




