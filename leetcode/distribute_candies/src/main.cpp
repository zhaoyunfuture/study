#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> s;
        set<int>::iterator sit;
        int size = candies.size();        
        int max = size/2;
        bool ismax = false;
        for(int i=0;i<size;++i) {
            sit = s.find(candies.at(i));
            if(sit == s.end()) {
                s.insert(candies.at(i));
                if(s.size()>=max) {
                    ismax = true;
                    break;
                }
            }else
                *sit++;
        }
        if(ismax)
            return max;
        else
            return s.size();
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




