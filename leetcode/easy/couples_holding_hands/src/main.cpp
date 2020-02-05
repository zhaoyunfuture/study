#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int swapcouple(vector<int>& row){
        int pair = row.size()/2;
        if(pair==0)
            return 0;
        if(pair==2)
            return 1;
        if(pair==3)
            return 2;

        for(int i=0;i<row.size()-1;i++){
            if(row.at(i)==row.at(row.size()-1)){
                if(i%2==0){
                    if(row.at(i+1)==row.at(row.size()-2))
                        row.erase(row.begin()+i,row.begin()+i+2);
                    else
                        row.at(i) = row.at(row.size()-2);                    
                }else{
                    if(row.at(i-1)==row.at(row.size()-2))
                        row.erase(row.begin()+i-1,row.begin()+i+1);
                    else
                        row.at(i) = row.at(row.size()-2);     
                }
                break;
            }
        }
        row.pop_back();
        row.pop_back();       
        return swapcouple(row)+1;        
    }
    int minSwapsCouples(vector<int>& row) {        
        int half_val;
        vector<int> newrow;
        for(int i=0;i<row.size();i++){
            if(i%2==0)
                half_val=row.at(i)/2;
            else{
                if(half_val!=row.at(i)/2){                   
                    newrow.push_back(half_val);
                    newrow.push_back(row.at(i)/2);
                }
            }
        }        
        return swapcouple(newrow);
    }
};
int main(int argc, char* argv[])
{
  
	return 0;
}




