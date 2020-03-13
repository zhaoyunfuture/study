#include <string.h>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    typedef struct{
        int pos;
        int val;
    }kv_t;
    typedef struct{
        kv_t min;
        kv_t max;
        int diff;
    }data_t;
   
    struct myclass {
      bool operator() (data_t i,data_t j) { return (i.diff>j.diff);}
    } myobject;
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len < 2)
            return 0;
        if(len == 2)
            return prices.at(1) >= prices.at(0)? (prices.at(1)-prices.at(0)): 0;
        vector<data_t> v;        
        bool flag = prices.at(1) >= prices.at(0)? 1:0;
        kv_t min;
        min.val = prices.at(1) >= prices.at(0)?prices.at(0):prices.at(1);
        min.pos = prices.at(1) >= prices.at(0)?0:1;
        for(int i=1;i<len-1;i++) {            
            if(prices.at(i+1)>=prices.at(i)){           
                flag = true;                
                if(i+1==len-1){
                    data_t d;                    
                    d.min = min;
                    d.max.val = prices.at(len-1);
                    d.max.pos = len-1;
                    d.diff = prices.at(len-1)-min.val;
                    v.push_back(d);   
                }                                 
            }else{
                if(flag==1){                   
                    //cout << "max " << max << " min " << min << endl; 
                    data_t d;
                    d.min = min;
                    d.max.val = prices.at(i);
                    d.max.pos = i;
                    d.diff = prices.at(i)-min.val;
                    v.push_back(d);
                }
                min.val = prices.at(i+1);
                min.pos = i+1;
                flag=false;
            }
        }
        cout << v.size() << endl;
        sort (v.begin(), v.end(), myobject);
        for(int i=0;i<v.size();i++)
            cout << v.at(i).diff << " ";
        int out;
        if(v.size()==0)            
            return 0;
        if(v.size()==1)
            out = v.at(0).diff;
        if(v.size()==2)
            out = v.at(0).diff+v.at(1).diff;
        if(v.size()>2){
            int i=1;
            while(i+1<v.size() && v.at(i+1).max.pos +1 == v.at(i).min.pos) {
                i++;    
            }
            if(v.at(1).max.val-v.at(i).min.val > v.at(1).diff)
                out = v.at(0).diff + v.at(1).max.val-v.at(i).min.val;
            else
                out = v.at(0).diff+v.at(1).diff;
        }
        return out;
    }
};

class Solution {
public:
    struct myclass {
      bool operator() (int i,int j) { return (i>j);}
    } myobject;
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len < 2)
            return 0;
        if(len == 2)
            return prices.at(1) >= prices.at(0)? (prices.at(1)-prices.at(0)): 0;
        vector<int> v;        
        bool flag = prices.at(1) >= prices.at(0)? 1:0;
        int min = prices.at(1) >= prices.at(0)?prices.at(0):prices.at(1);
        for(int i=1;i<len-1;i++) {            
            if(prices.at(i+1)>=prices.at(i)){                
                flag = true;                
                if(i+1==len-1)
                    v.push_back(prices.at(len-1)-min);                
            }else{
                if(flag==1){
                    int max = prices.at(i);
                    //cout << "max " << max << " min " << min << endl; 
                    v.push_back(max-min);
                }
                min = prices.at(i+1);
                flag=false;
            }
        }
        //cout << v.size() << endl;
        sort (v.begin(), v.end(), myobject);
        //for(int i=0;i<v.size();i++)
        //    cout << v.at(i) << " ";
        int out;
        if(v.size()==0)            
            return 0;
        if(v.size()==1)
            out = v.at(0);
        if(v.size()>=2)
            out = v.at(0)+v.at(1);
        return out;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    //int myints[] = {3,3,5,0,0,3,1,4};
    int myints[] = {2,1,4};
    vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );
    cout << s.maxProfit(v);
	return 0;
}




