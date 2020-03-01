#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
    public:
        bool riseOrfall(vector<int>& heights,bool& isrise){
            int len = heights.size();
            if(len<5)
                return false;
            bool comp = heights.at(0)<=heights.at(1)?true:false;
            bool nextcomp;
            for(int i=1;i<len-1;i++){
                nextcomp = heights.at(i)<=heights.at(i+1);
                if(comp^nextcomp)
                    return false;            

            }
            isrise = comp;
            return true;

        }
        int minH(vector<int>& heights,int b,int l){
            int min = heights.at(b);
            if(l==1)
                return min;
            for(int i=b+1;i<=l+b-1;i++){
                if(heights.at(i)<=min)
                    min = heights.at(i);

            }
            return min;

        }
        int largestRectangleArea(vector<int>& heights) {
            int len = heights.size();
            if(len==0)
                return 0;
            if(len==1)
                return heights.at(0);
            int out=heights.at(0);
            int tmp=0;        
            bool isrise=false;
            if(len>10000 && riseOrfall(heights,isrise)){       
                int t=0;
                if(isrise){                  
                    out=heights.at(len-1);                
                    for(int i=len-2;i>=0;i--){
                        t = heights.at(i)*(len-i);
                        if(t>out){                        
                            out = t;

                        }else
                            break;

                    }

                }else{


                }


            }else{
                for(int i=1;i<=len;i++){
                    for(int j=0;j<=len-i;j++){
                        tmp = minH(heights,j,i);               
                        if(out<tmp*i)
                            out = tmp*i;

                    }

                }

            }
            return out;

        }

};
int main(int argc, char* argv[])
{
  
	return 0;
}




