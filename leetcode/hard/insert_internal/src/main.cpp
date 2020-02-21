#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
    public:  
        typedef enum{        
            E_IN,
            E_OUT
        }E_type;
        typedef struct{
            int index_l;
            int index_r;
        }pos_t;
        typedef struct{
            E_type type;
            union {
                int index;
                pos_t pos;
            }val;
        }data_t;

        void fillInfo(int newVal,data_t& d,vector<vector<int>>& intervals){
            int intersize = intervals.size();
            d.type = E_OUT;
            d.val.pos.index_l = 0;
            d.val.pos.index_r = 0;
            for(int i=0;i<intersize;i++){
                if(newVal>=intervals.at(i).at(0) && newVal<=intervals.at(i).at(1)){
                    d.type = E_IN;
                    d.val.index = i;
                    return;
                }
                if((i==0 && newVal<intervals.at(i).at(0)) ||
                        (i==intersize-1 && newVal>intervals.at(i).at(1))){                
                    d.val.pos.index_l = i;
                    d.val.pos.index_r = i;
                    return;
                }
                if(newVal>intervals.at(i).at(1))
                    d.val.pos.index_l = i;
                if(newVal<intervals.at(i).at(0))
                    d.val.pos.index_r = i;
                if(d.val.pos.index_l < d.val.pos.index_r){
                    cout << d.val.pos.index_l << ' ' << d.val.pos.index_r << endl;
                    return;
                }            
            }      
        }
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            vector<vector<int>> res;
            int intersize = intervals.size();
            int newsize = newInterval.size();
            if(intersize==0){
                res.push_back(newInterval);
                return res;
            }
            if(newsize==0)
                return intervals;
            if(intervals.at(0).at(0)>newInterval.at(1)){
                intervals.insert(intervals.begin(),newInterval);
                return intervals;
            }
            if(intervals.at(intersize-1).at(1)<newInterval.at(0)){
                intervals.push_back(newInterval);
                return intervals;
            }
            data_t d0;
            data_t d1;

            fillInfo(newInterval.at(0),d0,intervals);
            fillInfo(newInterval.at(1),d1,intervals);

#if 0
            cout << d0.type << ' ' << d0.val.index << ' ' << d0.val.pos.index_l << ' ' << d0.val.pos.index_r << endl;
            cout << d1.type << ' ' << d1.val.index << ' ' << d1.val.pos.index_l << ' ' << d1.val.pos.index_r << endl;
#endif
            if(d0.type == E_IN){
                vector<int> tmp;
                tmp.push_back(intervals.at(d0.val.index).at(0));
                if(d0.val.index!=0){
                    for(int i=0;i<d0.val.index;i++)
                        res.push_back(intervals.at(i));
                }
                if(d1.type == E_IN){
                    tmp.push_back(intervals.at(d1.val.index).at(1));
                    res.push_back(tmp);
                    for(int i=d1.val.index+1;i<intersize;i++)
                        res.push_back(intervals.at(i));
                }else{
                    tmp.push_back(newInterval.at(1));
                    res.push_back(tmp);
                    if(d1.val.pos.index_l != d1.val.pos.index_r){
                        for(int i=d1.val.pos.index_r;i<intersize;i++)
                            res.push_back(intervals.at(i));
                    }
                }
            }else{
                vector<int> tmp;
                tmp.push_back(newInterval.at(0));
                if(d0.val.pos.index_l != d0.val.pos.index_r){
                    for(int i=0;i<=d0.val.pos.index_l;i++)
                        res.push_back(intervals.at(i));
                }
                if(d1.type == E_IN){
                    tmp.push_back(intervals.at(d1.val.index).at(1));
                    res.push_back(tmp);
                    for(int i=d1.val.index+1;i<intersize;i++)
                        res.push_back(intervals.at(i));
                }else{
                    tmp.push_back(newInterval.at(1));
                    res.push_back(tmp);
                    if(d1.val.pos.index_l != d1.val.pos.index_r){
                        for(int i=d1.val.pos.index_r;i<intersize;i++)
                            res.push_back(intervals.at(i));
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




