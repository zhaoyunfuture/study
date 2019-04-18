#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isleaf(vector<vector<int>>& grid,int ha,int hb,int va,int vb){
        bool isl = true;
        for(int i=va,i<=vb;++i) {
            for(int j=ha,j<=hb;++j) {
                if(grid.at(va).at(ha)!=grid.at(i).at(j)){
                    isl = false;
                    break;
                }
            }
            if(isl == false)
                break;
        }        
        return isl;
    }
    void build(Node* root,vector<vector<int>>& grid,int ha,int hb,int va,int vb) {       
        root->isLeaf = true;
        if(isleaf(grid,ha,(hb-ha)/2,va,(vb-va)/2)){
            root->topLeft = new Node(grid.at(va).at(ha),true,NULL,NULL,NULL,NULL);        
        }else {
            root->topLeft = new Node(grid.at(va).at(ha),false,NULL,NULL,NULL,NULL);
            build(root->topLeft,grid,ha,(hb-ha)/2,va,(vb-va)/2);
            root->isLeaf = false;
        }

        if(isleaf(grid,ha,(hb-ha)/2,va,(vb-va)/2)){
            root->topRight = new Node(grid.at(va).at(ha),true,NULL,NULL,NULL,NULL);     
        }else{
            build(root->topRight,grid,ha,(hb-ha)/2,va,(vb-va)/2);
            root->isLeaf = false;
        }

        if(isleaf(grid,ha,(hb-ha)/2,va,(vb-va)/2)){
            root->bottomLeft = new Node(grid.at(va).at(ha),true,NULL,NULL,NULL,NULL);
        }else{
            build(root->bottomLeft,grid,ha,(hb-ha)/2,va,(vb-va)/2);
            root->isLeaf = false;
        }

        if(isleaf(grid,ha,(hb-ha)/2,va,(vb-va)/2)){
            root->bottomRight = new Node(grid.at(va).at(ha),true,NULL,NULL,NULL,NULL);
        }else{
            build(root->topLeft,grid,ha,(hb-ha)/2,va,(vb-va)/2);
            root->bottomRight = false;
        }       

    }
    Node* construct(vector<vector<int>>& grid) {
        if(grid.size()==0)
            return NULL;

    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




