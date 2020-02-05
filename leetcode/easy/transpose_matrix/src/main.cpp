#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int r = A.size();
        if(r==0)
            return A;
        int c = A.at(0).size();
        int t[r] = {0};
        vector<vector<int>> res;
        vector<int> v(t,t+r);
        for(int i=0;i<c;i++){
            res.push_back(v);
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                res.at(j).at(i) = A.at(i).at(j);
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




