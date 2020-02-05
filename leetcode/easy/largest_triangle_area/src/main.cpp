#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res=0;

        for(int i=0;i<points.size()-2;i++)
        {
            for(int j=i+1;j<points.size()-1;j++)
            {

                for(int k=j+1;k<points.size();k++)
                {

                    double x1=points[i][0];
                    double x2=points[j][0];
                    double x3=points[k][0];

                    double y1=points[i][1];
                    double y2=points[j][1];
                    double y3=points[k][1];

                    double cres=0;

                    cres = abs((x1*(y2-y3))+(x2*(y3-y1))+(x3*(y1-y2)))/2;

                    res=max(cres,res);
                }
            }
        }

        return res;
    }
};
int main(int argc, char* argv[])
{
  
	return 0;
}




