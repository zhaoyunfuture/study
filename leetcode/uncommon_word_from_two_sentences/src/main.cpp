#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
	public:
		void storeInMap(string a,map<string,int>& m){
			int len = a.length();
			if(len==0)
				return;
			map<string,int>::iterator mit;
			string t;
			string remain(a);        
			std::size_t found = remain.find_first_of(" ");
			while (found!=std::string::npos)
			{
				t = remain.substr(0,found);
				//cout<< t<<endl;
				mit = m.find(t);
				if(mit == m.end())
					m.insert(pair<string,int>(t,1));
				else
					mit->second++;
				remain = remain.substr(found+1);
				//cout <<remain<<endl;
				found = remain.find_first_of(" ");
			}
			mit = m.find(remain);
			if(mit == m.end())
				m.insert(pair<string,int>(remain,1));
			else
				mit->second++;
		}
		vector<string> uncommonFromSentences(string A, string B) {
			vector<string> v;
			map<string,int> m;
			map<string,int>::iterator mit;
			storeInMap(A,m);
			storeInMap(B,m);
			//cout << m.size();
			for(mit=m.begin();mit!=m.end();mit++){
				//cout << mit->first;
				if(mit->second==1)
					v.push_back(mit->first);
			}
			return v;
		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




