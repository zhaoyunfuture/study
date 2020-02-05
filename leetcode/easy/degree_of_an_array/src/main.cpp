#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    struct comp {
        bool operator() (const int& lhs, const int& rhs) const
        {return lhs>rhs;}
    };
    int findShortestSubArray(vector<int>& nums) {
        int size = nums.size();
        if(size < 2)
            return size;
        if(size ==2){
            if(nums.at(0)==nums.at(1))
                return 2;
            else
                return 1;
        }
        map<int,vector<int>> m;
        map<int,vector<int>>::iterator mit;
        for(int i=0;i<size;++i){
            mit = m.find(nums.at(i));
            if(mit == m.end()){
                vector<int> v;
                v.push_back(i);
                v.push_back(0);
                v.push_back(1);
                m.insert(pair<int,vector<int>>(nums.at(i),v));
            }else{
                mit->second.at(1) = i;
                mit->second.at(2) += 1;
            }                
        }
        map<int,int,comp> degreeM;
        map<int,int,comp>::iterator degreeMit;
        for(map<int,vector<int>>::iterator it=m.begin(); it!=m.end();++it) {
            degreeMit = degreeM.find(it->second.at(2));
            if(degreeMit == degreeM.end()){
                if(it->second.at(1)==0)
                    degreeM.insert(pair<int,int>(it->second.at(2),0));
                else
                    degreeM.insert(pair<int,int>(it->second.at(2),it->second.at(1)-it->second.at(0)));
            }else{
                if(it->second.at(1)==0)
                    continue;
                if(degreeMit->second > (it->second.at(1)-it->second.at(0)))
                    degreeMit->second = it->second.at(1)-it->second.at(0);
            }
        }
        degreeMit = degreeM.begin();
        return degreeMit->second+1;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




