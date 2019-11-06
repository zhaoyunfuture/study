#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<vector<int>> even;
        vector<vector<int>> odd;
        for(int i=0;i<A.size();i++){
            if(i%2==0){
                if(A.at(i)%2==0)
                    continue;
                else{
                    if(even.size()==0){
                        vector<int> v;
                        v.push_back(i);
                        v.push_back(A.at(i));
                        odd.push_back(v);
                    }else{
                        int val = A.at(i);
                        A.at(i) = even.at(even.size()-1).at(1);
                        A.at(even.at(even.size()-1).at(0)) = val;
                        even.pop_back();
                    }
                }
            } 
            if(i%2!=0){
                if(A.at(i)%2!=0)
                    continue;
                else{
                    if(odd.size()==0){
                        vector<int> v;
                        v.push_back(i);
                        v.push_back(A.at(i));
                        even.push_back(v);
                    }else{
                        int val = A.at(i);
                        A.at(i) = odd.at(odd.size()-1).at(1);
                        A.at(odd.at(odd.size()-1).at(0)) = val;
                        odd.pop_back();
                    }
                }
            } 
        }
        return A;
    }
};
int main(int argc, char* argv[])
{
    Solution s;
    vector<int> v;
    vector<int> o;

    v.push_back(4);
    v.push_back(2);
    v.push_back(5);
    v.push_back(7);
    o = s.sortArrayByParityII(v);
	return 0;
}




