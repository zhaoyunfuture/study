#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
	public:
		bool findcontinMap(map<int,int>& m,int k){
			map<int,int>::iterator mit;
			mit = m.find(k);
			if(mit == m.end())
				return false;
			else{
				if(mit->second > 0)
					return true;
				else
					return false;
			}
		}
		int findContentChildren(vector<int>& g, vector<int>& s) {
			int max_s;
			int cont=0;
			if(s.size()==0)
				return 0;
			max_s = s.at(0);
			map<int,int> m;
			map<int,int>::iterator mit;
			//find out max of s_vector, and cache in map
			for(int i=0;i<s.size();++i){
				if(s.at(i)>max_s)
					max_s = s.at(i);
				mit = m.find(s.at(i));
				if(mit == m.end())
					m.insert(pair<int,int>(s.at(i),1));
				else
					mit->second +=1;
			}
			for(int j=0;j<g.size();++j){
				if(g.at(j)>max_s)
					continue;
				mit = m.find(g.at(j));
				if(mit != m.end()){
					if(mit->second > 0){
						cont++;
						mit->second -=1;
						continue;
					}else{
						int t = g.at(j)++;
						if(t>max_s)
							continue;
						while(!findcontinMap(m,t)){
							t++;
							if(t>max_s)
								break;
						}
						if(t>max_s)
							continue;
						else{
							cont++;
							mit = m.find(t);
							mit->second -=1;
						}                        
					}
				}else{
					int t = g.at(j)++;
					if(t>max_s)
						continue;
					while(!findcontinMap(m,t)){
						t++;
						if(t>max_s)
							break;
					}
					if(t>max_s)
						continue;
					else{
						cont++;
						mit = m.find(t);
						mit->second -=1;
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




