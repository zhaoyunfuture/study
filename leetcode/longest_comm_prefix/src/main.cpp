#include <string.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string s="";
		vector<string>::iterator it = strs.begin();
		vector<string>::iterator it_s = strs.begin()++;
		vector<string>::iterator it_t;
		if(strs.size() == 0)
			return s;
		if(strs.size() == 1)
			return *(strs.begin());
		for(unsigned int i = 0;i < (*it).size();++i)
		{
			bool comm = true;
			for(it_t = it_s;it_t != strs.end(); ++it_t)
			{
				if((*it_t).size() == 0)
				{
					comm = false;
					break;
				}
				if(i > ((*it_t).size()-1))
				{
					comm = false;
					break;
				}
				if((*it).at(i) != (*it_t).at(i))
				{
					comm = false;
					break;
				}
			}

			if(comm)
			{
				s.push_back((*it).at(i));
			}
			else
				break;
		}
		return s;
	}
};

int main(int argc, char* argv[])
{
	printf("hello \r\n");	
	Solution s;
	vector<string> vs;
	//vs.push_back("pleaes");
	//vs.push_back("pleac");
	//vs.push_back("please");
	vs.push_back("");
	vs.push_back("b");
	cout << s.longestCommonPrefix(vs) <<endl;	
	return 0;
}
