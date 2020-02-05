#include <string.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int len = A.size();
        if(len==1)
            return A;
        bool done =false;
        for(int i=0;i<len;i++){
            int j=0;

            while(A.at(j)%2 ==0){
                j++;
                if(j == len){
                    done =true;
                    break;
                }
            }
            if(done)
                break;
            int val = A.at(j);
            A.erase(A.begin()+j);
            A.push_back(val);            
        }
        return A;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> v;
    v.push_back(0);
    v.push_back(2);
    s.sortArrayByParity(v);
	return 0;
}




