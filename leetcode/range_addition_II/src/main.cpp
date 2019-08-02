#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int con = ops.size();
        if(con == 0)
            return m*n;
        int min_a=ops.at(0).at(0);
        int min_b=ops.at(0).at(1);
        for(int i=0;i<con;i++) {
            if(min_a > ops.at(i).at(0))
                min_a = ops.at(i).at(0);
            if(min_b > ops.at(i).at(1))
                min_b = ops.at(i).at(1);
        }
        return min_a*min_b;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




