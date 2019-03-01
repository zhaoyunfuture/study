#include <string.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stack>
#include <math.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int i = x;
        int j = 0;
        int res = 0;
        std::stack<int> s;
        while(!((i%10)&&(i/10%10)))
        {
            s.push(i%10);
            i = i/10;
        }
        while(!s.empty())
        {
            res += s.top() * pow(10,j);
            s.pop();
            j++;
        }
        return res;
    }
};
    
int main(int argc, char* argv[])
{
  printf("hello \r\n");
  Solution s;
  int i = 123;
  printf("%d",s.reverse(i));
  return 0;
}
