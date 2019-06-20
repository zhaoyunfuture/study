#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
	public:
		int fib(int N) {
			if(N == 0)
				return 0;
			if(N == 1)
				return 1;
			return fib(N-1)+fib(N-2);
		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




