#include <string.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverse(vector<int>& v,int start,int len){        
        int a=start;
        int b=start+len;
        int tmp;
        for(;a<b;a++,b--){
            tmp = v.at(a);
            v.at(a) = v.at(b);
            v.at(b) = tmp;
        }
    }
    vector<int> diStringMatch(string S) {
        vector<int> di_bulk;
        vector<int> out;
        int d_max=0;
        int i_max=0;
        int len = S.length();
        if(S.at(0)=='I')
            i_max = 1;
        else
            d_max = 1;
        char last = S.at(0);
        int bulk = 1;
        for(int i=1;i<len;i++){
            if(S.at(i)=='I')
                i_max++;
            else
                d_max++;
            if(last == S.at(i)){
                bulk++;
            }else{
                di_bulk.push_back(bulk);
                last = S.at(i);
                bulk=1;
            }
        }
        di_bulk.push_back(bulk);
        #if 0
        cout << i_max << ' ' << d_max << endl;
        cout << di_bulk.size() << endl;
        for(int i=0;i<di_bulk.size();i++)
            cout << di_bulk.at(i);
        #endif
        if(d_max == 0){
            for(int i=0;i<len+1;i++)
                out.push_back(i);
            return out;
        }
        if(i_max == 0){
            for(int i=len;i>=0;i--)
                out.push_back(i);
            return out;
        }
        /*initial*/
        bool reverse_even = false;
        if(d_max>i_max || (d_max==i_max && S.at(0)=='D')){
            for(int i=len;i>=0;i--)
                out.push_back(i);
            if(S.at(0)=='I')
                reverse_even=true;
        }else{
            for(int i=0;i<len+1;i++)
                out.push_back(i);
            if(S.at(0)=='D')
                reverse_even=true;
        }
        int index=0;
        for(int i=0;i<di_bulk.size();i++){
            if(reverse_even && i%2==0)
                reverse(out,index,di_bulk.at(i));
            if(!reverse_even && i%2!=0)
                reverse(out,index,di_bulk.at(i));
            index += di_bulk.at(i);

        }
        return out;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> v;
    v = s.diStringMatch("DDDD");
    cout << endl;
    for(int i=0;i<v.size();i++)
        cout << v.at(i) << ' ' ;

	return 0;
}




