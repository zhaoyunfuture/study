#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
    public:
        bool pointInLine(int dela_x,int dela_y,int dela_x1,int dela_y1){
            if(dela_x1*dela_y==dela_x*dela_y1)
                return true;
            else
                return false;

        }
        bool checkStraightLine(vector<vector<int>>& coordinates) {
            int len = coordinates.size();
            if(len<=2)
                return true;
            int dx = coordinates.at(0).at(0)-coordinates.at(1).at(0);
            int dy = coordinates.at(0).at(1)-coordinates.at(1).at(1);
            int dx1,dy1;
            for(int i =2;i<len;i++){
                dx1 = coordinates.at(0).at(0)-coordinates.at(i).at(0);
                dy1 = coordinates.at(0).at(1)-coordinates.at(i).at(1);
                if(!pointInLine(dx,dy,dx1,dy1)){
                    return false;

                }

            }
            return true;

        }

};
int main(int argc, char* argv[])
{
  
	return 0;
}




