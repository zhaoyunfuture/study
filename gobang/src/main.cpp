#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h> //for system clear
using namespace std;

int keys[15][15];
int score[15][15];

void prepareTable(int keys[15][15]){
	const int size = 15*2+14+1;
	char filled[size];
	memset(filled,0,size);

	printf("%s\n","  01 02 03 04 05 06 07 08 09 10 11 12 13 14 15");
	for(int i=1; i<=15; i++){
		printf("%02d",i);
		//reset filled part for new line
		for(int i=0;i<size-1;i++){
			if((i+1)%3 == 0){
				filled[i] = '|';
			}else {
				filled[i] = ' ';
			}
		}
		for(int j=1;j<=15;j++){
			switch (keys[i-1][j-1]) {
				case 1:
					filled[(j-1)*3] = 'X';
					filled[(j-1)*3+1] = 'X';
					break;
				case 2:
					filled[(j-1)*3] = '(';
					filled[(j-1)*3+1] = ')';
					break;
			}
			
		}
		printf("%s\n",filled);
	}
}

void _AI(int keys[15][15],int score[15][15]){
    int maxVal = 0;
    int max_row, max_col;

    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(score[i][j] > maxVal){
                maxVal = score[i][j];
                max_row = i;
                max_col = j;
            }       
        }
    }
    keys[max_row][max_col] = 2;

}

void dumpScore(int score[15][15]){
    printf("\nscore value:\n");
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            printf("%02d ",score[i][j]);
        }
        printf("\n");
    }
}

void calc(const vector<vector<int>>& vv,int score[15][15]){
    int rect_num = 0;
    int circ_num = 0;

    for(int i=0;i<5;i++){
        if(vv.at(i).at(2) == 1){
            rect_num += 1;
        }else if(vv.at(i).at(2) == 2){
            circ_num += 1;
        }
    }

    if(rect_num != 0 && circ_num != 0){
        //no score: have both white and black chess
        return;
    }

    if(rect_num == 4 || circ_num == 4){
        for(int i=0;i<5;i++){
            if(vv.at(i).at(2) == 0){
                score[vv.at(i).at(0)][vv.at(i).at(1)] += 40;
            }
        }
    }

    if(rect_num == 3 || circ_num == 3){
        for(int i=0;i<5;i++){
            if(vv.at(i).at(2) == 0){
                score[vv.at(i).at(0)][vv.at(i).at(1)] += 20;
            }
        }
    }

    if(rect_num == 2 || circ_num == 2){
        for(int i=0;i<5;i++){
            if(vv.at(i).at(2) == 0){
                score[vv.at(i).at(0)][vv.at(i).at(1)] += 2;
            }
        }
    }

    if(rect_num == 1 || circ_num == 1){
        for(int i=0;i<5;i++){
            if(vv.at(i).at(2) == 0){
                score[vv.at(i).at(0)][vv.at(i).at(1)] += 1;
            }
        }
    }

}

bool isWin(int keys[15][15],int score[15][15],int &winner){
    vector<vector<int>> vv;
    vector<int> v;
    // for row check '--'
    for(int i=0;i<15;i++){
        for(int j=0;j<15-5;j++){
            vv.clear();
            if( keys[i][j] != 0 &&
                keys[i][j]==keys[i][j+1] &&
                keys[i][j]==keys[i][j+2] &&
                keys[i][j]==keys[i][j+3] &&
                keys[i][j]==keys[i][j+4] ){    
                winner = keys[i][j];
                return true;
            }
            for(int k=0;k<5;k++){
                v.clear();
                v.push_back(i);
                v.push_back(j+k);
                v.push_back(keys[i][j+k]);
                vv.push_back(v);
            }
            calc(vv,score);
        }
    }
    // for col check '|'
    for(int j=0;j<15;j++){
        for(int i=0;i<15-5;i++){
            vv.clear();
            if( keys[i][j] != 0 &&
                keys[i][j]==keys[i+1][j] &&
                keys[i][j]==keys[i+2][j] &&
                keys[i][j]==keys[i+3][j] &&
                keys[i][j]==keys[i+4][j] ){    
                winner = keys[i][j];
                return true;
            }
            for(int k=0;k<5;k++){
                v.clear();
                v.push_back(i+k);
                v.push_back(j);
                v.push_back(keys[i+k][j]);
                vv.push_back(v);
            }
            calc(vv,score);
        }
    }
    // for slash check '\'
    for(int i=0;i<15-5;i++){
        for(int j=0;j<15-5;j++){
            vv.clear();
            if( keys[i][j] != 0 &&
                keys[i][j]==keys[i+1][j+1] &&
                keys[i][j]==keys[i+2][j+2] &&
                keys[i][j]==keys[i+3][j+3] &&
                keys[i][j]==keys[i+4][j+4] ){    
                winner = keys[i][j];
                return true;
            }
            for(int k=0;k<5;k++){
                v.clear();
                v.push_back(i+k);
                v.push_back(j+k);
                v.push_back(keys[i+k][j+k]);
                vv.push_back(v);
            }
            calc(vv,score);
        }
    }
    // for slash check '/'
    for(int i=0;i<15-5;i++){
        for(int j=4;j<15-5;j++){
            vv.clear();
            if( keys[i][j] != 0 &&
                keys[i][j]==keys[i+1][j-1] &&
                keys[i][j]==keys[i+2][j-2] &&
                keys[i][j]==keys[i+3][j-3] &&
                keys[i][j]==keys[i+4][j-4] ){    
                winner = keys[i][j];
                return true;
            }
            for(int k=0;k<5;k++){
                v.clear();
                v.push_back(i+k);
                v.push_back(j-k);
                v.push_back(keys[i+k][j-k]);
                vv.push_back(v);
            }
            calc(vv,score);
        }
    }

    return false;
}

typedef enum {
    VS,
    AI
}mode;

int main(int argc, char* argv[])
{
	int steps = 0;
	int row, col;
	const char* role[2] = {"[rectangle]", "[circle]"};
    int winner;
    int battleMode;
    string bm;
    bool goon = true;
    string cont;
    mode m = VS;
	memset(keys,0,sizeof(keys));
	memset(score,0,sizeof(score));

    cout << "choose mode(0/1): VS or AI  " ;
    cin >> battleMode;
    m = battleMode==1?AI:VS;
    bm = battleMode==1?"AI":"VS";
    cout << "you choose mode: " << bm << endl;
	
    while(goon){
		system("clear");
        cout << " mode: " << bm << endl;
		prepareTable(keys);
        
        dumpScore(score);
        memset(score,0,sizeof(score));
        if(isWin(keys,score,winner)){
            cout << "well done! " << role[winner-1] << endl;
            cout << "go on? enter 'yes' or 'no' " ;
            cin >> cont;
            if(cont == "no"){
                goon = false;
            }else{
                memset(keys,0,sizeof(keys));
                steps = 0;
                system("clear");
                prepareTable(keys);
            }
        }
        
        if(!goon)
            break;

        if(VS == m){
            cout << role[steps%2] << " input your position(row/col): " ;
            cin >> row >> col;
            keys[row-1][col-1] = steps%2 + 1;
            steps++;
        }else{
            cout << role[0] << " input your position(row/col): " ;
            cin >> row >> col; 
            keys[row-1][col-1] = 1;
            if(isWin(keys,score,winner)){
                cout << "well done, you killed the AI!" << endl;
                cout << "go on? enter 'yes' or 'no' " ;
                cin >> cont;
                if(cont == "no"){
                    goon = false;
                }else{
                    memset(keys,0,sizeof(keys));
                }
            }else{
                _AI(keys,score);
            }
        }
    }

    cout << "bye" << endl;
	return 0;
}




