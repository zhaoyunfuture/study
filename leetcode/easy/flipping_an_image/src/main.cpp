#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i=0;i<A.size();++i){
            int m = 0;
            int n = A.at(i).size()-1;
            if(n==0){
                if(A.at(i).at(0))
                    A.at(i).at(0) = 0;
                else
                    A.at(i).at(0) = 1;
            }
            while(m<n){
                if(A.at(i).at(m)==A.at(i).at(n)){
                    if(A.at(i).at(m)){
                        A.at(i).at(m) = 0;
                        A.at(i).at(n) = 0;
                    }else{
                        A.at(i).at(m) = 1;
                        A.at(i).at(n) = 1;
                    }
                }
                m++;
                n--;
                if(m==n){
                    if(A.at(i).at(m)){
                        A.at(i).at(m) = 0;
                        A.at(i).at(n) = 0;
                    }else{
                        A.at(i).at(m) = 1;
                        A.at(i).at(n) = 1;
                    }
                }
            }            
        }
        return A;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




