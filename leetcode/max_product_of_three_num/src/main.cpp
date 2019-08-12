#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    struct mapcomp {
        bool operator() (const int& lhs, const int& rhs) const
        {return lhs>rhs;}
    };
    int maximumProduct(vector<int>& nums) {
        map<int,int,mapcomp> m;

        map<int,int,mapcomp>::iterator mit;
        map<int,int,mapcomp>::reverse_iterator mrit;
        int size = nums.size();
        if(size == 3)
            return nums.at(0)*nums.at(1)*nums.at(2);
        for(int i=0;i<size;++i) {
            mit = m.find(nums.at(i));
            if(mit == m.end())
                m.insert(pair<int,int>(nums.at(i),1));
            else
                mit->second++;
        }
        int multi = 0;
        int rmulti = 0;
        int prod = 1;
        int prod1 = 1;
        int biggest = m.begin()->first;
        map<int,int,mapcomp> m1(m);
        for(mit=m.begin();mit!=m.end();mit++) {
            if(mit->first ==0)
                continue;
            while(mit->second >0) {
                prod *= mit->first;
                mit->second--;
                multi++;
                if(multi == 3)
                    break;
            }
            if(multi == 3)
                break;
        }
        for(mrit=m1.rbegin();mrit!=m1.rend();mrit++) {
            if(mrit->first >=0)
                break;

            while(mrit->second >0) {
                prod1 *= mrit->first;
                mrit->second--;
                rmulti++;
                if(rmulti == 2)
                    break;
            }
            if(rmulti == 2)
                break;
        }        
        prod1 *= biggest;
        if(multi !=3)
            return 0;
        else
            return prod>prod1?prod:prod1;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




