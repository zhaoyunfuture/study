#include <string.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		vector<vector<int>> generate(int numRows) {
			if(numRows <= 0) {
				vector<vector<int>> a;
				return a;
			}
			else {
				vector<vector<int>> a(numRows);

				for (unsigned i=0; i<a.size(); i++)	{
					if(i == 0) {
						a.at(i).push_back(1);
					}
					else if(i == 1) {
						a.at(i).push_back(1);
						a.at(i).push_back(1);
					}
					else {
						for (unsigned j=0; j<i+1; j++) {
							if((j == 0)||(j == i))
								a.at(i).push_back(1);
							else {
								a.at(i).push_back( a.at(i-1).at(j-1) + a.at(i-1).at(j));	
							}
						}
					}
				}
				return a;
			}
		}

		vector<int> getRow(int rowIndex) {
			vector<vector<int>> res = generate(rowIndex+1);
			return res.at(rowIndex);
		}
};

int main(int argc, char* argv[])
{
	Solution s,s1;
	vector<vector<int>> v;
	vector<int> v1;
	v = s.generate(5);

	for(unsigned i=0; i<v.size(); i++)
	{
		for(unsigned j=0; j<v.at(i).size(); j++)
			cout << v.at(i).at(j) << ' ' ;
		cout << endl;
	}
	v1 = s1.getRow(4);
	for(unsigned j=0; j<v1.size(); j++)
	{
		cout << v1.at(j) << ' ' ;
	}
	return 0;
}



