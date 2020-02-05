#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> v;
        if(K==0)
            return A;
        int t = K;
        vector<int> vk;
        vk.push_back(t%10);
        t /= 10;
        while(t){
            vk.insert(vk.begin(),t%10);
            t /= 10;
        }
        int ia = A.size()-1;
        int ik = vk.size()-1;
        bool carry = false;
        int sum = A.at(ia) + vk.at(ik);
        if(sum>9)
            carry = true;
        v.push_back(sum%10);
        ia--; ik--;
        while(ia>=0 || ik>=0){
            if(ia>=0 && ik>=0){
                sum = A.at(ia) + vk.at(ik) + (carry?1:0);                
                v.insert(v.begin(),sum%10);
                ia--; ik--;
            }else if(ia>=0 && ik<0){
                sum = A.at(ia) + (carry?1:0);               
                v.insert(v.begin(),sum%10);
                ia--;
            }else if(ik>=0 && ia<0){
                sum = vk.at(ik) + (carry?1:0);                
                v.insert(v.begin(),sum%10);
                ik--;
            }
            if(sum>9)
                carry = true;
            else
                carry =false;
        }
        if(carry)
            v.insert(v.begin(),1);        
        return v;       
    }
};
int main(int argc, char* argv[])
{
    Solution s;
    vector<int> v;
    vector<int> o;

    v.push_back(1);
    v.push_back(2);
    v.push_back(0);
    v.push_back(0);
    o = s.addToArrayForm(v,34);

    for(int i=0;i<o.size();i++)
        cout << o.at(i) << ' ' ;
	return 0;
}




