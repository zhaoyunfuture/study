#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
	public:
		int arrangeCoins(int n) {
			if(n<2)
				return n;

			unsigned int m = n;
			m *=2;
			unsigned int i = 1;
			while((i)*(i+1)<m){
				i++;

				if(i==65536)
					break;
			}
			if(i==65536)
				return i-1;
			if((i)*(i+1)==m)
				return i;
			else 
				return i-1;

		}
};
int main(int argc, char* argv[])
{
  
	return 0;
}




