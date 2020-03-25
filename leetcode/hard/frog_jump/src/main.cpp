#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool canjump(vector<int>& diff,int index,int move,int& nextindex){
        if(diff.at(index)==move){
            nextindex = index;
            return true;
        }
        if(diff.at(index)>move){            
            return false;
        }
        int t = diff.at(index);
        while(t<move){
            t += diff.at(++index);
        }
        if(t==move){
            nextindex = index;
            return true;
        }
        return false;
    }
    bool jump(vector<int>& diff,int index,int move){
        if(index==diff.size()-1)
            return true;
        bool n1=false;
        bool n0=false;
        bool n_1=false;
        int n1_idx,n0_idx,n_1idx;
               
        if(canjump(diff,index+1,move+1,n1_idx)){
            n1 = jump(diff,n1_idx,move+1);
        }
        if(n1)
            return true;
        
        if(canjump(diff,index+1,move,n0_idx)){
            n0 = jump(diff,n0_idx,move);
        }
        if(n0)
            return true;
        
        if(move>1 && canjump(diff,index+1,move-1,n_1idx)){
            n_1 = jump(diff,n_1idx,move-1);
        }
        if(n_1)
            return true;
        
        return false;        
    }
    bool canCross(vector<int>& stones) {
        int len = stones.size();        
        if(stones.at(1)>1)
            return false;
        
        vector<int> diff;
        for(int i=1;i<len;i++){
            diff.push_back(stones.at(i)-stones.at(i-1));  
        }
        int sum=0;
        bool can = true;
        for(int i=1;i<diff.size();i++){            
            if(abs(diff.at(i)-diff.at(i-1))>1){
                can = false;                
            }
            sum += diff.at(i-1);
        }  
        if(can)
            return true;
        if(diff.at(diff.size()-1)>sum)
            return false;
        
        return false;
        
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




