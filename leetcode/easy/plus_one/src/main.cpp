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

            for(int i = size; i > 0 ;--i)
            {
                if(digits.at(i-1) < 9)
                {
                    digits.at(i-1) += 1;
                    break;
                }
                else
                {
                    digits.at(i-1) = 0;
                    if(i == 1)
                    {
                        digits.insert(digits.begin(),1);
                    }
                }
            }
            return digits;
        }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> v;
    vector<int> u;
    std::vector<int>::iterator it;

    v.push_back(9);
    v.push_back(9);
    v.push_back(9);
    u = s.plusOne(v);
    for(it = u.begin();it != u.end();++it)
    {
        cout << *it << endl;
    }
	return 0;
}




