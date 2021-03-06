#include <string.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int m;
        int len;
        std::vector<int> v;
        std::vector<int>::iterator it;
        std::vector<int>::reverse_iterator rit;

        if (x < 0)
            return false;
        
        m = x;
        while((m%10 != 0) || (m/10 != 0))
        {
            v.push_back(m%10);
            m /= 10;
        }
        len = v.size();
        it = v.begin(),
        rit = v.rbegin();
        for(int i = 0;i < len/2;++it,++rit,++i)
        {
            if(*it != *rit)
                return false;
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
  printf("hello \r\n");
  Solution s;

  cout << s.isPalindrome(121) << endl;
  cout << s.isPalindrome(-121) << endl;
  cout << s.isPalindrome(1231) << endl;
  return 0;
}
