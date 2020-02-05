#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isOK(vector<int>& bits, int index) {
        if(index == 0){
            if( bits.at(0) == 0)
                return true;
            else
                return false;
        }else{
            if(bits.at(index) == 1){
                if(bits.at(index-1) == 0)
                    return false;
                else {
                    if(index-2>=0)
                        return isOK(bits,index-2);
                    else
                        return true; 
                }
            }else {
                if(index<2)
                    return true;
                else{
                    return isOK(bits,index-1) || isOK(bits,index-2);
                }
            }
        }

    }
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.size()==1)
            return true;
        return isOK(bits,bits.size()-2);
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




