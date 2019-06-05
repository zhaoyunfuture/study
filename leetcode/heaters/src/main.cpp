#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int len_he = heaters.size();
        int len_ho = houses.size();
        if(len_he == 0 || len_ho == 0)
            return 0;
        int b,c;
        int a = 0;

        for(int i=0;i<len_ho;++i) {
            if(houses.at(i)-heaters.at(0)>0)
                b = houses.at(i)-heaters.at(0);
            else
                b = heaters.at(0)-houses.at(i);
            for(int j=0;j<len_he;++j) {
                if(houses.at(i)-heaters.at(j)>0)
                    c = houses.at(i)-heaters.at(j);
                else
                    c = heaters.at(j)-houses.at(i);
                if(c<b)
                    b = c;
            }

            if(b>a)
                a = b;
        }
        return a;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




