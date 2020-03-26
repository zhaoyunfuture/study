#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string process(string board){
        if(board.empty())
            return board;
        int b=0;
        int l=0;
        string p=board;
        string t;
        while(find(p,b,l)){
            if(l==p.length()){
                p="";
                break;
            }else{
                if(b==0){
                    p=p.substr(l);
                }else{
                    t.clear();
                    t = p.substr(0,b);
                    if(b+l!=p.length()){
                        t.append(p.substr(b+l));
                    }
                    p = t;
                }
            }
        }
        return p;
    }
    bool find(string s,int& b,int& l){
        char c=s.at(0);
        int len = s.length();
        if(len<3)
            return false;
        int cont = 1;
        b = 0;
        for(int i=1;i<len;i++){
            if(s.at(i)==c){
                cont++;
            }else{
                if(cont>=3){
                    l = i-b;
                    return true;
                }
                cont=1;
                b = i;
                c = s.at(i);
            }
        }
        if(cont>=3){
            l = len-b;
            return true;
        }
        return false;        
    }
};
int main(int argc, char* argv[])
{
    Solution s;
    int i;
    int len;
    string ss="WWBGGGBBWBBB";
    cout <<s.find(ss,i,len)<<endl;
    cout << i<<endl;
    cout << len<<endl;
    cout << s.process(ss)<<endl;
	return 0;
}




