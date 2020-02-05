#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:    
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix.at(0).size();
        if(r == 1)
            return true;
        int i = r-2;
        int j = 0;
        int i1,j1;
        bool isSame = true;
        while(j!=c-1){
            isSame = true;
            i1 = i;
            j1 = j;
            while(i1+1<r && j1+1<c){
                if(matrix.at(i).at(j) != matrix.at(i1+1).at(j1+1)){
                    isSame = false;
                    break;
                }
                i1 +=1;
                j1 +=1;
            }
            if(!isSame)
                return false;
            if(i==0)
                j++;
            else
                i--;
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




