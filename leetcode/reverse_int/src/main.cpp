#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <limits.h>
#include <math.h>
using namespace std;
#if 0
class Solution {
public:
    int reverse(int x) {
		int i = x;
		int j = 0;
		int sum = 0;
		std::stack<int> s;
	    unsigned int p =2<<31 -1;
		if((x>0) && (x > p))
			return 0;
		if((x<0))
		{
		    unsigned int p = x;
			unsigned int con = 2<<30;
			if(p == con)
				return 0;
		}
		while((i%10 != 0) || (i/10 != 0))
		{
		    s.push(i%10);
			i /= 10;
		}
		while (!s.empty())
		{
		    sum += s.top()* pow(10,j);
			s.pop();
			j++;
		}

		if((sum>0) && (sum > p))
			return 0;
		if((x >0) && (sum < 0))
		    return 0;
		if(sum <0)
		{
			unsigned int p = sum;
			unsigned int con = 2<<30;
			if(p == con)
				return 0;
		}

        return sum;
	}
};
#endif
class Solution {
	public:
		int reverse(int x) {
			bool neg = x < 0;
			if (x == INT_MIN) return 0;
			if (neg) x = -x;
			int r = 0;
			while (x != 0) {
				if (r > INT_MAX / 10 || r == INT_MAX / 10 && x % 10 > 7)
					return 0;
				r = r * 10 + x % 10;
				x = x / 10;
			}
			if (neg) r = -r;
			return r;
		}
};
int main(int argc, char* argv[])
{
    Solution s;
	cout << s.reverse(-123) << endl;
	cout << s.reverse(123) << endl;
	cout << s.reverse(-2147483648) << endl;
	cout << s.reverse(1534236469) << endl;
	cout << s.reverse(1463847412) << endl;
	cout << s.reverse(-1563847412) << endl;
 cout << "INT_MIN" << INT_MIN <<endl;	
    return 0;
}




