#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canChange(int income,vector<int>& w){
        if(income == 5){
            w.at(0) += 1;
            return true;
        }else if(income == 10){
            if(w.at(0)!=0){
                w.at(1)++;
                w.at(0)--;
                return true;
            }else
                return false;
        }else {
            if(w.at(1)!=0) {
                if(w.at(0)!=0){
                    w.at(1)--;
                    w.at(0)--;
                    return true;
                }else
                    return false;
            }else{
                if(w.at(0)<3)
                    return false;
                else{
                    w.at(0) -= 3;
                    return true;
                }
            }
        }
    }
    bool lemonadeChange(vector<int>& bills) {
        int len = bills.size();
        if(len == 0)
            return false;
        if(bills.at(0) != 5)
            return false;
        vector<int> wallet;
        wallet.push_back(0);
        wallet.push_back(0);

        for(int i=0;i<len;i++){
            if(canChange(bills.at(i),wallet))
                continue;
            else
                return false;
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




