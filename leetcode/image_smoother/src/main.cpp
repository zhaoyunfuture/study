#include <string.h>
#include <string>
#include <iostream>
using namespace std;


class Solution {
	public:
		bool exist(int x,int y,vector<vector<int>>& M) {
			if(x < 0 || y < 0)
				return false;
			if(x >= M.size())
				return false;
			if(y >= M.at(x).size())
				return false;
			else
				return true;
		}

		int round(int x,int y,vector<vector<int>>& M) {
			int cont = 0;
			int sum = 0;
			for(int i=-1;i<2;i++) {
				for(int j=-1;j<2;j++) {
					if(exist(x+i,y+j,M)) {
						cont++;
						sum +=M.at(x+i).at(y+j);
					}
				}
			}
			return floor(sum/cont);

		}
		vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
			vector<vector<int>> N;
			vector<int> t;
			for(int i=0;i<M.size();i++) {
				t.clear();
				for(int j=0;j<M.at(i).size();j++){
					t.push_back(round(i,j,M));
				}
				N.push_back(t);
			}
			return N;

		}
};
int main(int argc, char* argv[])
{
  
	return 0;
}




