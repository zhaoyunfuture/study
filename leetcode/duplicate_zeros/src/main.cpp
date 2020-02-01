#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
    public:
        void duplicateZeros(vector<int>& arr) {
            vector<int> res;
            int len = arr.size();
            vector<int>::iterator it= arr.begin();
            for(int i=0;i<len;i++){
                if(arr.at(i)!=0){
                    res.push_back(arr.at(i));

                }else{
                    res.push_back(0);
                    res.push_back(0);

                }
                if(res.size()==len)
                    break;
                if(res.size()>len){
                    while(res.size()!=len){
                        res.pop_back();

                    }
                    break;

                }

            }
            arr = res;

        }

};
int main(int argc, char* argv[])
{
  
	return 0;
}




