#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
    public:
        struct myclass {
            bool operator() (int i,int j) { return (i<j); }

        } comp;
        int lastStoneWeight(vector<int>& stones) {
            if(stones.size()==0)
                return 0;
            if(stones.size()==1)
                return stones.at(0);
            if(stones.size()==2)
                return stones.at(0)>stones.at(1)?stones.at(0)-stones.at(1):stones.at(1)-stones.at(0);
            sort (stones.begin(), stones.end(), comp);   
            int smash=stones.at(stones.size()-1)-stones.at(stones.size()-2);
            stones.pop_back();
            stones.pop_back();
            stones.push_back(smash);
            return lastStoneWeight(stones);

        }

};
int main(int argc, char* argv[])
{
  
	return 0;
}




