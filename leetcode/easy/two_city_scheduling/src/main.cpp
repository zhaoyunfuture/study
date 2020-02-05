#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    struct _d {
        int x;
        int y;
        bool xless;
        int delta;
    };
    static bool _delta (_d a,_d b) { return (a.delta>b.delta); }

    int twoCitySchedCost(vector<vector<int>>& costs) {        
        int less_x=0;
        int min=0;
        int len = costs.size();
        vector<_d> delta_cost;

        for(int i=0;i<len;i++){
            _d val;
            val.x = costs.at(i).at(0);
            val.y = costs.at(i).at(1);
            if(costs.at(i).at(0)<costs.at(i).at(1)){
                less_x++;
                val.xless = true;
                val.delta = val.y - val.x;
                min += costs.at(i).at(0);

            }else{
                val.xless = false;
                val.delta = val.x - val.y;
                min += costs.at(i).at(1);               
            }
            delta_cost.push_back(val);
        }
        if(less_x*2 == len)
            return min;
        else{
            min=0;
            int contx=0;
            int conty=0;
            sort(delta_cost.begin(),delta_cost.end(),_delta);
            for(int i=0;i<len;i++){
                if(contx*2==len){
                    min += delta_cost.at(i).y;
                }else if(conty*2==len){
                    min += delta_cost.at(i).x;
                }else{
                    if(delta_cost.at(i).xless){
                        contx++;
                        min += delta_cost.at(i).x;
                    }else{
                        conty++;
                        min += delta_cost.at(i).y;
                    }
                }
            }            
            return min;
        }
    }
};
int main(int argc, char* argv[])
{
  
	return 0;
}




