#include <string.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
        vector<int> plusOne(vector<int>& digits) {
            int size = digits.size();
            if(size == 0)
            {
                digits.push_back(1);
                return digits;
            }
            bool flag = false;
            for(int i = size; i > 0 ;--i)
            {
                if(digits.at(i-1) < 9) 
            }

        }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




