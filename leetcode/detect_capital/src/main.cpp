#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
	public:
		bool detectCapitalUse(string word) {
			int size = word.size();
			if(size==0)
				return false;
			if(size==1)
				return true;
			bool first=false;
			bool second=false;

			if(isupper(word.at(0)))
				first = true;
			if(isupper(word.at(1)))
				second = true;

			if(!first&&second)
				return false;
			if(size == 2)
				return true;
			else {
				if(first&&second) {
					for(int i=2;i<size;++i){
						if(!isupper(word.at(i)))
							return false;
					}
					return true;
				}else {
					for(int i=2;i<size;++i){
						if(isupper(word.at(i)))
							return false;
					}
					return true;
				}
			}
		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




