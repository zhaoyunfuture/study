#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    struct myclass {
      bool operator() (int i,int j) { return (i<j);}
    } myobject;
    void nextmove(vector<vector<int>>& dungeon,
                  vector<int>& v,int r,int c,
                  int initial,int curHP){
        int row = dungeon.size();
        int col = dungeon.at(0).size();
        if(r==row-1 && c==col-1){
            int hp = curHP+dungeon.at(r).at(c);
            if(hp<=0)
                v.push_back(initial-hp+1);
            else
                v.push_back(initial);
            return;
        }
        if(r==row-1){
            int hp = curHP+dungeon.at(r).at(c);
            int update_initial;
            if(hp<=0){
                update_initial = initial-hp+1;
                hp = 1;
            }
            else
                update_initial = initial;
            nextmove(dungeon,v,r,c+1,update_initial,hp);                
        }else if(c==col-1){
            int hp = curHP+dungeon.at(r).at(c);
            int update_initial;
            if(hp<=0){
                update_initial = initial-hp+1;
                hp = 1;
            }
            else
                update_initial = initial;
            nextmove(dungeon,v,r+1,c,update_initial,hp);        
        }else{
            int hp = curHP+dungeon.at(r).at(c);
            int update_initial;
            if(hp<=0){
                update_initial = initial-hp+1;
                hp = 1;
            }
            else
                update_initial = initial;
            nextmove(dungeon,v,r+1,c,update_initial,hp);  
            nextmove(dungeon,v,r,c+1,update_initial,hp);  
        }
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<int> v;
        nextmove(dungeon,v,0,0,0,0);
        cout << v.size() << endl;
        for(int i=0;i<v.size();i++)
            cout << v.at(i) << " ";
        sort (v.begin(), v.end(), myobject);
        if( v.at(0)==0)
            return 1;
        return v.at(0);
    }
};
int main(int argc, char* argv[])
{
  
	return 0;
}




