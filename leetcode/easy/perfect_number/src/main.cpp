#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
	public:
		bool checkPerfectNumber(int num) {
			if(num ==1 || num ==2)
				return false;

			int sum=1;

			for(int i=2;i<=num/2;++i) {
				if(num%i == 0)
					sum+=i;
			}

			if(sum == num)
				return true;
			else
				return false;
		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




