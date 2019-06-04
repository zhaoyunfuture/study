#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.size()==0)
            return 0;
        int v = grid.size();
        int h = grid.at(0).size();
        int conth = 0;
        int contv = 0;
        int contotal = 0;
        bool lastland = false;
        for(int i=0;i<v;++i){
            for(int j=0;j<h;++j){
                if(grid.at(i).at(j)==1){
                    contotal ++;
                    if(lastland)
                        conth++;
                    else
                        lastland = true;
                }
                else
                    lastland = false; 
            }
            lastland = false;
        }
        lastland = false;
        for(int k=0;k<h;++k){
            for(int r=0;r<v;++r){
                if(grid.at(r).at(k)==1){                    
                    if(lastland)
                        contv++;
                    else
                        lastland = true;
                }else
                    lastland = false; 
            }
            lastland = false;
        }        
        return contotal*4-conth*2-contv*2;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




