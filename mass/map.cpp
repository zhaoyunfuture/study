/*************************************************************************
    > File Name: map.cpp
    > Author: Jacob
    > Mail: zyfuture@qq.com 
    > Created Time: 2016年04月23日 星期六 13时57分55秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<cstdlib>
using namespace std;

class state
{
	public:
		state();
		state(const string n):name(n){}
		
		string getname() const {
			return name;
		}
	private:
		string name;
};

map<string,state*>stateMap;

int findKeybyValue(map<string,state*>statemap,state* s){
	map<string,state*>::iterator it = statemap.begin();
	for(it;it != statemap.end();it++){
		state* temp = it->second;
		if(temp == s)
			return atoi((it->first).c_str());
	}
	return -1;
}
int main()
{
	state state1("a"),state2("b"),state3("c");
	cout << "state1's name == " << state1.getname() <<endl;
	string a="111";
	string b="222";
	string c="333";
	stateMap.insert(pair<string,state*>(a,&state1));
	stateMap.insert(pair<string,state*>(b,&state2));
	stateMap.insert(pair<string,state*>(c,&state3));
	cout << "state's <a> count is " << stateMap.count(a) << endl;
	cout << "state's <a> statePoint is " << stateMap[a] << endl;
	cout << "state's <a> string is " << findKeybyValue(stateMap,stateMap[a]) << endl;
	cout << "state's <c> string is " << findKeybyValue(stateMap,stateMap[c]) << endl;
	return 1;
}
