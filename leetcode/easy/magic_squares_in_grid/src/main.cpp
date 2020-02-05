#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isMagic(int r,int c,vector<vector<int>>& grid){
        int num[10] = {0};
        int rowSum[3] ={0};
        int colSum[3] ={0};
        for(int i=r;i<r+3;++i){
            int sum = 0;
            for(int j=c;j<c+3;++j){
                int t = grid.at(i).at(j);
                if(t==0 || t>9)
                    return false;
                if(num[t])
                    return false;
                else
                    num[t] = 1;
                sum += t;
            }
            rowSum[i-r] = sum;
        }
        if(rowSum[0]!=rowSum[1] || rowSum[0]!=rowSum[2])
            return false;

        int le = 0;
        int ri = 0;
        for(int j=c;j<c+3;++j){
            int sum = 0;
            for(int i=r;i<r+3;++i){
                int t = grid.at(i).at(j);                
                sum += t;
                if(i-r == j-c)
                    le += t;
                if( (i-r == 0 && j-c == 2) ||
                        (i-r == 2 && j-c == 0) || 
                        (i-r == 1 && j-c == 1) )
                    ri += t;
            }
            colSum[j-c] = sum;
        }
        if(colSum[0]!=colSum[1] || colSum[0]!=colSum[2])
            return false;
        if(rowSum[0]!=colSum[0] || rowSum[0] !=le || rowSum[0]!=ri)
            return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int lenRow = grid.size();
        if(lenRow < 3)
            return 0;
        int lenCol = grid.at(0).size();
        if(lenCol < 3)
            return 0;

        int c = 0;
        for(int i=0;i<=lenRow-3;i++){
            for(int j=0;j<=lenCol-3;j++){
                if(isMagic(i,j,grid))
                    c++;
            }
        }
        return c;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




