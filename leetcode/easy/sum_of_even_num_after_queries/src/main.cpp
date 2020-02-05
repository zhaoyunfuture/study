#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> v;
        int sum=0;
        for(int i=0;i<A.size();i++){
            if(A.at(i)%2==0)
                sum += A.at(i);
        }
        for(int i=0;i<queries.size();i++){
            if(A.at(queries.at(i).at(1))%2==0)
                sum -= A.at(queries.at(i).at(1));

            A.at(queries.at(i).at(1)) += queries.at(i).at(0);
            if(A.at(queries.at(i).at(1))%2==0)
                sum += A.at(queries.at(i).at(1));
            v.push_back(sum);
        }
        return v;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




