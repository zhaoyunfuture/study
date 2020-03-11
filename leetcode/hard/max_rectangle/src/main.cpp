#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    typedef struct{
        int pro;
        int row;
        int col;
    }data_t;
    typedef struct{        
        int row;
        int col;
    }pos_t;
    struct myclass {
      bool operator() (data_t i,data_t j) { return (i.pro>j.pro);}
    } comp;
    bool inRec(vector<pos_t>& pos,int br,int bc,int r,int c){
        for(int i=0;i<pos.size();i++){
            if( (pos.at(i).row >= br) && 
                (pos.at(i).row < br+r) &&
                (pos.at(i).col >= bc) &&
                (pos.at(i).col < bc+c) )
                return false;
        }
        return true;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row==0)
            return 0;
        int col = matrix.at(0).size();
        vector<data_t> data;
        vector<pos_t> pos;
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                data_t d;
                pos_t p;
                d.row = i;
                d.col = j;
                d.pro = i*j;
                data.push_back(d);
                if(matrix.at(i-1).at(j-1)=='0'){
                    p.row = i-1;
                    p.col = j-1;
                    pos.push_back(p);
                }
            }
        }
        
        if(pos.size()==0)
            return row*col;
        if(pos.size()==row*col)
            return 0;
        int max=0;
        sort(data.begin(),data.end(),comp);
        data.erase(data.begin());
        for(int i=0;i<data.size();i++){
            if(i==data.size()-1)
                return 1;
            for(int j=0;j<=row-data.at(i).row;j++){
                for(int k=0;k<=col-data.at(i).col;k++){
                    if(inRec(pos,j,k,data.at(i).row,data.at(i).col)){
                        max = data.at(i).pro;
                        goto out;
                    }
                }
            }
        }
    out:
        return max;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




