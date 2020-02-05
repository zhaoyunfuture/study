#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    struct myclass {
        bool operator() (int i,int j) { return (i<j);}
    } myobject;
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int minus_num=0;
        sort (A.begin(), A.end(), myobject);
        if(A.at(0)>=0)
            minus_num=0;
        else{
            for(int i=0;i<A.size();i++){
                if(A.at(i)<0)
                    minus_num++;
                else
                    break;
            }
        }
        int sum=0;
        if(minus_num == 0){
            for(int i=0;i<A.size();i++){
                if(K%2!=0 && i==0)
                    sum -= A.at(i);
                else
                    sum += A.at(i);                
            }
        }else if(minus_num>=K){
            for(int i=0;i<A.size();i++){
                if(i<K)
                    sum -= A.at(i);
                else
                    sum += A.at(i);
            }
        }else{
            if((K-minus_num)%2==0){
                for(int i=0;i<A.size();i++){
                    if(i<minus_num)
                        sum -= A.at(i);
                    else
                        sum += A.at(i);
                }
            }else{
                int min=A.at(0)>0?A.at(0):(-A.at(0));               
                for(int i=0;i<A.size();i++){                     
                    if(i<minus_num)
                        sum -= A.at(i);
                    else
                        sum += A.at(i);                    
                    min = A.at(i)>0?(min>A.at(i)?A.at(i):min):(min>(-A.at(i))?(-A.at(i)):min);
                }               
                sum -= min*2;
            } 
        }
        return sum;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




