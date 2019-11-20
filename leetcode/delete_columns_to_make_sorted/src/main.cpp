#include <string.h>
#include <string>
#include <iostream>
using namespace std;


ass Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int size = A.size();
        if(size<2)
            return 0;
        int cont=0;
        for(int i=0;i<A.at(0).size();i++){
            for(int j=1;j<A.size();j++){
                if(A.at(j-1).at(i)>A.at(j).at(i)){
                    cont++;
                    break;
                }
            }
        }
        return cont;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




