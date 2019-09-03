#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> skipC(vector<string>& ops) {
        vector<string> v;
        int size = ops.size();
        if(size == 1) {
            v = ops;
            return v;
        }

        string c("C");
        for(int i=0;i<size;++i){
            if(ops.at(i) == c)
                v.pop_back();
            else{
                v.push_back(ops.at(i));                
            }
        }
        return v;
    }
    vector<int> toInt(vector<string>& ops) {
        vector<int> v;
        string d("D");
        string p("+");
        int l1 = 0;
        int l2 = 0;
        for(int i=0;i<ops.size();++i) {
            if(ops.at(i) == d){
                l1 = v.at(v.size()-1);
                v.push_back(2*l1);
            }                
            else if(ops.at(i) == p){
                l1 = v.at(v.size()-1);
                l2 = v.at(v.size()-2);
                v.push_back(l1+l2);
            }  
            else
                v.push_back(atoi(ops.at(i).c_str()));
        }
        return v;
    }
    int calPoints(vector<string>& ops) {
        vector<string> v;
        vector<int> vint;
        v = skipC(ops);
        int size = v.size();
        int score = 0;

        vint = toInt(v);
        for(int i=0;i<vint.size();++i){            
            score +=vint.at(i);
        }       
        return score;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> v;
    for (int i=1; i<=10; i++) v.push_back(i);

    v.erase (v.begin()+5);
    v.erase (v.begin()+6);
    for (unsigned i=0; i<v.size(); ++i)
            std::cout << ' ' << v[i];
      std::cout << '\n';
	return 0;
}




