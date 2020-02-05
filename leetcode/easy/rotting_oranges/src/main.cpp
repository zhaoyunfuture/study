#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool valid(int i,int j,vector<vector<int>>& grid){
        int row = grid.size();
        int col = grid.at(0).size();
        if(i>=0 && i<row && j>=0 && j<col)
            return true;
        else
            return false;
    }

    void change(vector<vector<int>>& grid){
        vector<int> v;
        vector<vector<int>> rotten;
        int row = grid.size();
        int col = grid.at(0).size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid.at(i).at(j)==2){
                    v.clear();
                    v.push_back(i);
                    v.push_back(j);
                    rotten.push_back(v);
                }
            }
        }
        for(int i=0;i<rotten.size();i++){
            int ir = rotten.at(i).at(0);
            int ic = rotten.at(i).at(1);
            if(valid(ir-1,ic,grid) && grid.at(ir-1).at(ic)!=0)
                grid.at(ir-1).at(ic) = 2;
            if(valid(ir+1,ic,grid) && grid.at(ir+1).at(ic)!=0)
                grid.at(ir+1).at(ic) = 2;
            if(valid(ir,ic-1,grid) && grid.at(ir).at(ic-1)!=0)
                grid.at(ir).at(ic-1) = 2;
            if(valid(ir,ic+1,grid) && grid.at(ir).at(ic+1)!=0)
                grid.at(ir).at(ic+1) = 2;
        }
    }
    bool allrotten(vector<vector<int>>& grid){
        int row = grid.size();
        int col = grid.at(0).size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){ 
                if(grid.at(i).at(j)==1)
                    return false;
            }
        }
        return true;
    }
    int countfresh(vector<vector<int>>& grid){
        int row = grid.size();
        int col = grid.at(0).size();
        int count=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){ 
                if(grid.at(i).at(j)==1)
                    count++;
            }
        }
        return count;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        bool hasfresh = false;      
        bool hasrotten = false;
        bool allempty = true;
        int val;
        int row = grid.size();
        int col = grid.at(0).size();
        int freshNum=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                val = grid.at(i).at(j);
                if(val==1){
                    allempty = false;
                    hasfresh = true;     
                    freshNum++;
                }else if(val==2){
                    allempty = false;
                    hasrotten = true;
                }
            }
        }

        if(allempty)
            return 0;
        if(!hasrotten)
            return -1;
        if(!hasfresh)
            return 0;
        int num=0;
        int tmp;
        while(hasfresh){
            change(grid);
            tmp = countfresh(grid);
            if(tmp==freshNum)
                return -1;
            else
                freshNum = tmp;
            num++;
            if(allrotten(grid))
                hasfresh = false;
        }
        return num;
    }
};

int main(int argc, char* argv[])
{
    vector<int> v;
    vector<vector<int>> vv;
    Solution s;
    v.push_back(0);
    v.push_back(1);
    vv.push_back(v);
    cout << s.orangesRotting(vv)<<endl;
	return 0;
}




