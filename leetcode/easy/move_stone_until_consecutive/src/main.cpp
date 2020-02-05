#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
    public:
        struct myclass {
            bool operator() (int i,int j) { return (i<j); }

        } comp;
        vector<int> numMovesStones(int a, int b, int c) {
            int gap_1,gap_2;
            vector<int> res;
            vector<int> v;
            v.push_back(a);
            v.push_back(b);
            v.push_back(c);
            sort(v.begin(),v.end(),comp);
            gap_1 = v.at(1)-v.at(0);
            gap_2 = v.at(2)-v.at(1);
            if(gap_1==1 && gap_2==1){
                res.push_back(0);
                res.push_back(0);
                return res;

            }
            if(gap_1==1 || gap_2==1){
                res.push_back(1);
                if(gap_1==1){                
                    res.push_back(v.at(2)-v.at(1)-1);
                    return res;

                }else{
                    res.push_back(v.at(1)-v.at(0)-1);
                    return res;

                }

            }
            if(gap_1==2 || gap_2==2){
                res.push_back(1);
                if(gap_1==2){                
                    res.push_back(v.at(2)-v.at(1));
                    return res;

                }else{
                    res.push_back(v.at(1)-v.at(0));
                    return res;

                }

            }
            res.push_back(2);
            res.push_back(v.at(2)-v.at(0)-2);
            return res;

        }

};
int main(int argc, char* argv[])
{
  
	return 0;
}




