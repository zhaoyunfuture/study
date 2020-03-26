#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#if 0
//for leetcode compile error : single usr vector instead of array
int step(string board, string hand){
        if(board.empty())
            return hand.length();
        if(hand.empty())
            return -1;
        vector<T_ball_idx> twoball;
        findtwoball(board,twoball);
        if(twoball.size()==0){
            vector<int> res;
            for(int i=0;i<board.length();i++){
                string b;
                string t;
                string h;
                if(has(hand,board.at(i),h,2)){
                    t = board;
                    t.erase(t.begin()+i);
                    b = t;
                    res.push_back(step(b,h));
                }else{
                    res.push_back(-1);
                }
            }
            int max=-1;
            for(int i=0;i<res.size();i++){
                if(res.at(i)>max)
                    max = res.at(i);
            }
            return max;
        }else{
            vector<int> res;
            vector<int> single;
            for(int i=0;i<board.length();i++){
                single.push_back(0);
            }
            
            for(int i=0;i<twoball.size();i++){
                string b=board;
                string h;
                string n;
                single.at(twoball.at(i).idx) = 1;
                single.at(twoball.at(i).idx-1) = 1;
                if(has(hand,twoball.at(i).c,h,1)){
                    b.insert(b.begin()+twoball.at(i).idx,twoball.at(i).c); 
                    n = process(b);
                    res.push_back(step(n,h));
                }else{
                    res.push_back(-1);
                }
            }
            for(int i=0;i<board.length();i++){
                if(single.at(i)==0){
                    string b;
                    string t;
                    string h;
                    if(has(hand,board.at(i),h,2)){
                        t = board;
                        t.erase(t.begin()+i);
                        b = t;
                        res.push_back(step(b,h));
                    }else{
                        res.push_back(-1);
                    }
                }
            }
            int max=-1;
            for(int i=0;i<res.size();i++){
                if(res.at(i)>max)
                    max = res.at(i);
            }
            return max;
        }
    }
#endif

class Solution {
public:
    typedef struct{
        char c;
        int idx;
    }T_ball_idx;
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
    void findtwoball(string board,vector<T_ball_idx>& twoball){
        int len = board.length();
        if(len<2)
            return;
        char c=board.at(0);
        T_ball_idx data;
        for(int i=1;i<len;i++){
            if(c==board.at(i)){
                data.c = c;
                data.idx = i;
                twoball.push_back(data);
            }else{
                c = board.at(i);
            }
        }
    }

    bool has(string hand,char c,string& newhand,int oneortwo){
        int len = hand.length();
        if(len<oneortwo)
            return false;
        int cont=0;
        for(int i=0;i<len;i++){
            if(hand.at(i)==c){
                cont++;
                if(cont>oneortwo)
                    newhand.push_back(hand.at(i));
            }else{
                newhand.push_back(hand.at(i));
            }
        }
        if(cont>=oneortwo)
            return true;
        else
            return false;
    }
    int step(string board, string hand){
        if(board.empty())
            return hand.length();
        if(hand.empty())
            return -1;
        vector<T_ball_idx> twoball;
        findtwoball(board,twoball);
        if(twoball.size()==0){
            vector<int> res;
            for(int i=0;i<board.length();i++){
                string b;
                string t;
                string h;
                if(has(hand,board.at(i),h,2)){
                    t = board;
                    t.erase(t.begin()+i);
                    b = t;
                    res.push_back(step(b,h));
                }else{
                    res.push_back(-1);
                }
            }
            int max=-1;
            for(int i=0;i<res.size();i++){
                if(res.at(i)>max)
                    max = res.at(i);
            }
            return max;
        }else{
            vector<int> res;
            int single[board.length()] = {0};
            for(int i=0;i<twoball.size();i++){
                string b=board;
                string h;
                string n;
                single[twoball.at(i).idx] = 1;
                single[twoball.at(i).idx-1] = 1;
                if(has(hand,twoball.at(i).c,h,1)){
                    b.insert(b.begin()+twoball.at(i).idx,twoball.at(i).c); 
                    n = process(b);
                    res.push_back(step(n,h));
                }else{
                    res.push_back(-1);
                }
            }
            for(int i=0;i<board.length();i++){
                if(single[i]==0){
                    string b;
                    string t;
                    string h;
                    if(has(hand,board.at(i),h,2)){
                        t = board;
                        t.erase(t.begin()+i);
                        b = t;
                        res.push_back(step(b,h));
                    }else{
                        res.push_back(-1);
                    }
                }
            }
            int max=-1;
            for(int i=0;i<res.size();i++){
                if(res.at(i)>max)
                    max = res.at(i);
            }
            return max;
        }
    }
    int findMinStep(string board, string hand) {
        int out = step(board,hand);
        if(out==-1)
            return -1;
        else
            return hand.length()-out;
    }
};
int main(int argc, char* argv[])
{
    Solution s;
#if 0
    int i;
    int len;
    string ss="WWBGGGBBWBBB";
    string sss="WWBGGBBWBB";
    cout <<s.find(ss,i,len)<<endl;
    cout << i<<endl;
    cout << len<<endl;
    cout << s.process(ss)<<endl;
    string has = "GBWBB";
    string out;
    string out1;
    cout << s.has(has,'B',out,2) << endl;
    cout<< out<< endl;
    cout << s.has(has,'B',out1,1) << endl;
    cout<< out1<< endl;
    string tt="abcde";
    tt.insert(tt.begin()+0,'F');
    cout << tt << endl;
    string board = "GGBBWWB";
    string hand = "GBWWB";
    cout<< s.step(board,hand) << endl;
#endif
    string board = "WWGWGW";
    string hand = "GWBWR";
    cout << s.findMinStep(board,hand) << endl;
	return 0;
}




