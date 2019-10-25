#include <string.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		typedef enum{en=0,ee,es,ew}direc;
		direc nextDir(direc curr, int cmd){
			int a = curr;
			direc ret;
			if(a==0 && cmd==-2)
				ret = ew;
			else if(a==3 && cmd==-1)
				ret = en;
			else{
				if(cmd==-1)
					ret =direc(a+1);
				if(cmd==-2)
					ret = direc(a-1);
			}
			return ret;
		}
		bool inSameLine(int& p,direc d,int m,int rOrc,int pair,vector<int> cur,vector<vector<int>>& obstacles){
			bool find=false;
			vector<int> stop;        
			for(int i=0;i<obstacles.size();i++){
				if(cur.at(rOrc)==obstacles.at(i).at(rOrc)){
					find = true;
					stop.push_back(obstacles.at(i).at(pair));
				}
			}
			if(!find)
				return false;
			else{
				int start = cur.at(pair);
				int end;
				if(d==en || d==ee){
					end = start+m;
					p = end;
					for(int i=0;i<stop.size();i++){
						if(p>=stop.at(i)&& stop.at(i)>start){
							p = stop.at(i)-1;
							find=true;
						}
					}
				}
				else{
					end = start-m;
					p = end;
					for(int i=0;i<stop.size();i++){
						if(p<=stop.at(i) && stop.at(i)<start){
							p = stop.at(i)+1;
							find=true;
						}
					}
				}            
			}
			return find;
		}
		bool canstop(int& p,direc d,int m,vector<int> cur,vector<vector<int>>& obstacles){
			if(obstacles.size()==0)
				return false;
			else{
				if(d==en || d==es){
					if(!inSameLine(p,d,m,0,1,cur,obstacles))
						return false;
					else{
						return true;
					}
				}else{
					if(!inSameLine(p,d,m,1,0,cur,obstacles))
						return false;
					else{
						return true;
					}
				}
			}   
		}
		vector<int> nextMov(direc d,int m,vector<int> cur,vector<vector<int>>& obstacles){
			vector<int> point;
			point.push_back(cur.at(0));
			point.push_back(cur.at(1));
			int val=0;
			switch (d){
				case en:
					if(!canstop(val,d,m,cur,obstacles))
						point.at(1) += m;
					else
						point.at(1) = val;
					break;
				case es:
					if(!canstop(val,d,m,cur,obstacles))
						point.at(1) -= m;
					else
						point.at(1) = val;
					break;
				case ee:
					if(!canstop(val,d,m,cur,obstacles))
						point.at(0) += m;
					else
						point.at(0) = val;
					break;
				case ew:
					if(!canstop(val,d,m,cur,obstacles))
						point.at(0) -= m;
					else
						point.at(0) = val;
					break;
				default:
					break;
			}
			return point;       

		}
		int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
			vector<vector<int>> v;
			vector<int> ori;
			ori.push_back(0);
			ori.push_back(0);
			v.push_back(ori);
			direc cur = en;
			for(int i=0;i<commands.size();i++){
				if(commands.at(i)<0)
					cur = nextDir(cur,commands.at(i));
				else
					v.push_back(nextMov(cur,commands.at(i),v.at(v.size()-1),obstacles));
			}
			int res = v.at(0).at(0)*v.at(0).at(0) + v.at(0).at(1)*v.at(0).at(1);
			cout << v.at(0).at(0) << v.at(0).at(1);
			int tmp;
			for(int i=1;i<v.size();i++){
				cout<< v.at(i).at(0) << v.at(i).at(1);
				tmp =  v.at(i).at(0)*v.at(i).at(0) + v.at(i).at(1)*v.at(i).at(1);
				if(res<tmp)
					res = tmp;
			}
			return res;
		}
};

int main(int argc, char* argv[])
{
	Solution s;
	int a[]={-2,8,3,7,-1};
	int b0[]={-4,-1};
	int b1[]={1,-1};
	int b2[]={1,4};
	int b3[]={5,0};
	int b4[]={4,5};
	int b5[]={-2,-1};
	int b6[]={2,-5};
	int b7[]={5,1};
	int b8[]={-3,-1};
	int b9[]={5,-3};
	vector<int> commands(a,a+5);
	vector<int> vb0(b0,b0+2);
	vector<int> vb1(b1,b1+2);
	vector<int> vb2(b2,b2+2);
	vector<int> vb3(b3,b3+2);
	vector<int> vb4(b4,b4+2);
	vector<int> vb5(b5,b5+2);
	vector<int> vb6(b6,b6+2);
	vector<int> vb7(b7,b7+2);
	vector<int> vb8(b8,b8+2);
	vector<int> vb9(b9,b9+2);
	vector<vector<int>> obstacles;
	obstacles.push_back(vb0);
	obstacles.push_back(vb1);
	obstacles.push_back(vb2);
	obstacles.push_back(vb3);
	obstacles.push_back(vb4);
	obstacles.push_back(vb5);
	obstacles.push_back(vb6);
	obstacles.push_back(vb7);
	obstacles.push_back(vb8);
	obstacles.push_back(vb9);

	cout <<" " <<s.robotSim(commands,obstacles);
	return 0;
}




