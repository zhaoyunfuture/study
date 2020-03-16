#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    struct myclass {
      bool operator() (int i,int j) { return (i<j);}
    } myobject;
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if(size==1)
            return size;
        vector<int> c;
        bool onlyfall = true;
        for(int i=0;i<size-1;i++){
            c.push_back(1);
            if(ratings.at(i)<ratings.at(i+1))
                onlyfall = false;
        }
        c.push_back(1);
        if(onlyfall){
            sort (ratings.begin(), ratings.end(), myobject); 
        }
        bool flag = false;
        do{
            flag = false;
            for(int i=0;i<size-1;i++){
                if(ratings.at(i)>ratings.at(i+1)){
                    if(c.at(i)<=c.at(i+1)){
                        c.at(i) += c.at(i+1) -c.at(i) + 1;
                        flag = true;
                    }
                }else if(ratings.at(i)<ratings.at(i+1)){
                    if(c.at(i)>=c.at(i+1)){
                        c.at(i+1) += c.at(i) -c.at(i+1) + 1;
                        flag = true;
                    }
                }
            }
        }while(flag);
        int out=0;
        for(int i=0;i<size;i++){
            out +=c.at(i);
        }
        return out;
    }
};
int main(int argc, char* argv[])
{
  
	return 0;
}




