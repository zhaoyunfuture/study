#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void twoothers(int in, int& out1,int& out2){
        switch(in){
            case 0:
            out1 = 1; out2 = 2;
            break;
            case 1:
            out1 = 0; out2 = 2;
            break;
            case 2:
            out1 = 0; out2 = 1;
            break;
            case 3:
            out1 = 4; out2 = 5;
            break;
            case 4:
            out1 = 3; out2 = 5;
            break;
            case 5:
            out1 = 3; out2 = 4;
            break;
            case 6:
            out1 = 7; out2 = 8;
            break;
            case 7:
            out1 = 6; out2 = 8;
            break;
            case 8:
            out1 = 6; out2 = 7;
            break;
            default:
                break;
        }
    }
    bool showInRow(char key,int r,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board.at(r).at(i)==key)
                return true;
        }
        return false;
    }
    bool showInCol(char key,int c,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board.at(i).at(c)==key)
                return true;
        }
        return false;
    }
    bool definite(char key,int r,int c,vector<vector<char>>& board){
        int r1,r2;
        int c1,c2;
        twoothers(r,r1,r2);
        twoothers(c,c1,c2);
        if(showInRow(key,r1,board)&&
           showInRow(key,r2,board)&&
           showInCol(key,c1,board)&&
           showInCol(key,c2,board)
          )
            return true;
        else
            return false;
    }
    bool definite_not(char key,int r,int c,vector<vector<char>>& board){
        if(showInRow(key,r,board)||showInCol(key,c,board))
            return true;
        else
            return false;
    }
    bool done(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.at(i).size();j++)
                if(board.at(i).at(j) == '.')
                    return false;
        }
        return true;
    }
    void notInCell(int cellNum,vector<vector<char>>& board,
                   vector<char>& vc,vector<vector<int>>& pos){
        int num[9] = {0};
        char n = '1';
        int r_start = cellNum/3;
        int c_start = cellNum%3;
        vector<int> p;
        for(int i=r_start*3;i<r_start*3+3;i++){
            for(int j=c_start*3;j<c_start*3+3;j++){
                if(board.at(i).at(j)=='.'){
                    p.clear();
                    p.push_back(i);
                    p.push_back(j);
                    pos.push_back(p);
                }else{
                    num[board.at(i).at(j)-n] = 1;
                }
            }
        }
        for(int i=0;i<9;i++){            
            if(num[i]==0)
                vc.push_back(n+i);
        }            
    }
    void print(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.at(i).size();j++)
                cout << board.at(i).at(j);
            cout << endl;
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        cout << "orginal" << endl;
        print(board); 
        vector<char> vc;
        vector<vector<int>> pos;
        bool keyed = false;
        while(!done(board)){            
            for(int i=8;i>=0;i--){
                vc.clear();
                pos.clear();
                keyed = false;
                notInCell(i,board,vc,pos);
                if(vc.size()==0 || pos.size()==0)
                    continue;
                for(int index_vc=0;index_vc<vc.size();index_vc++){
                    for(int index_pos=0;index_pos<pos.size();index_pos++){
                        if(definite(vc.at(index_vc),pos.at(index_pos).at(0),pos.at(index_pos).at(1),board)){
                            board.at(pos.at(index_pos).at(0)).at(pos.at(index_pos).at(1)) = vc.at(index_vc);
                            keyed = true;
                            cout << "input from def" << endl;
                            print(board);
                            break;
                        }
                    }
                    if(keyed)
                        break;
                }
                if(keyed)
                    continue;
                for(int index_vc=0;index_vc<vc.size();index_vc++){
                    int not_num = 0;
                    int not_pos[pos.size()] = {0};                    
                    for(int index_pos=0;index_pos<pos.size();index_pos++){
                        if(definite_not(vc.at(index_vc),pos.at(index_pos).at(0),pos.at(index_pos).at(1),board)){
                            not_num += 1;
                            not_pos[index_pos] = 1;
                        }
                    }
                    if(not_num+1 == pos.size()){
                        for(int i=0;i<pos.size();i++){
                            if(not_pos[i]==0){
                                board.at(pos.at(i).at(0)).at(pos.at(i).at(1)) = vc.at(index_vc);
                                cout << "input from undef" << endl;
                                print(board);
                            }
                        }
                    }
                }                
            }
        }
    }
};

int main(int argc, char* argv[])
{
    string s0 = "53..7....";
    string s1 = "6..195...";
    string s2 = ".98....6.";
    string s3 = "8...6...3";
    string s4 = "4..8.3..1";
    string s5 = "7...2...6";
    string s6 = ".6....28.";
    string s7 = "...419..5";
    string s8 = "....8..79";
    vector<char> v0;
    vector<char> v1;
    vector<char> v2;
    vector<char> v3;
    vector<char> v4;
    vector<char> v5;
    vector<char> v6;
    vector<char> v7;
    vector<char> v8;
    for(int i=0;i<s0.length();i++)
        v0.push_back(s0.at(i));
    for(int i=0;i<s1.length();i++)
        v1.push_back(s1.at(i));
    for(int i=0;i<s2.length();i++)
        v2.push_back(s2.at(i));
    for(int i=0;i<s3.length();i++)
        v3.push_back(s3.at(i));
    for(int i=0;i<s4.length();i++)
        v4.push_back(s4.at(i));
    for(int i=0;i<s5.length();i++)
        v5.push_back(s5.at(i));
    for(int i=0;i<s6.length();i++)
        v6.push_back(s6.at(i));
    for(int i=0;i<s7.length();i++)
        v7.push_back(s7.at(i));
    for(int i=0;i<s8.length();i++)
        v8.push_back(s8.at(i));
    vector<vector<char>> board;
    board.push_back(v0);
    board.push_back(v1);
    board.push_back(v2);
    board.push_back(v3);
    board.push_back(v4);
    board.push_back(v5);
    board.push_back(v6);
    board.push_back(v7);
    board.push_back(v8);
    
    Solution s;
    s.solveSudoku(board);
	return 0;
}




