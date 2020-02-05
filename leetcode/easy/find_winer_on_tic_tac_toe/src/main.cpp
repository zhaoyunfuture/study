#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
    public:
        bool isWin(int m[3][3],int& win){        
            bool out = false;
            do{
                for(int i=0;i<3;i++){
                    if(m[i][0]!=0 && m[i][0]==m[i][1] && m[i][0]==m[i][2]){
                        out = true;
                        win = m[i][0];
                        return out;
                    }
                }
                for(int i=0;i<3;i++){
                    if(m[0][i]!=0 && m[0][i]==m[1][i] && m[0][i]==m[2][i]){
                        out = true;
                        win = m[0][i];
                        return out;
                    }
                }
                if(m[1][1]!=0 && m[0][0]==m[1][1] && m[0][0]==m[2][2]){
                    out = true;
                    win = m[1][1];                
                    break;
                }
                if( m[1][1]!=0 && m[0][2]==m[1][1] && m[0][2]==m[2][0] ){
                    out = true;
                    win = m[1][1];                
                    break;
                }
            }while(0);
            return out;
        }
        string tictactoe(vector<vector<int>>& moves) {
            string Pending = "Pending";
            string Draw = "Draw";
            string A = "A";
            string B = "B";
            int map[3][3] = {0};
            int winer=0;
            int len = moves.size();
            if(len<5)
                return Pending;
            for(int i=0;i<len;i++){
                if(i%2==0){
                    map[moves.at(i).at(0)][moves.at(i).at(1)] = 1;

                }else{
                    map[moves.at(i).at(0)][moves.at(i).at(1)] = 2;
                }

            }
#if 0
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++)
                    cout<<map[i][j]<< ' ';
                cout << endl;

            }
#endif

            if(isWin(map,winer)){            
                if(winer==1)
                    return A;
                else
                    return B;
            }else{
                if(len<9)
                    return Pending;
                else
                    return Draw;
            }
        }
};

int main(int argc, char* argv[])
{
	return 0;
}

