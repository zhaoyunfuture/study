#include <string.h>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name == typed)
            return true;
        pair<char,int> p;       
        vector<pair<char,int>> v1;
        vector<pair<char,int>> v2;

        int len_name = name.length();
        if(len_name==1){
            v1.push_back(make_pair(name.at(0),1));
        }else{
            char a = name.at(0);
            int con = 1;
            for(int i=1;i<len_name;i++){
                if(a!=name.at(i)){
                    v1.push_back(make_pair(a,con));
                    a = name.at(i);
                    con =1;
                }else{
                    con++;
                }
            }
        }
        int len_typed = typed.length();
        if(len_typed==1){
            v2.push_back(make_pair(typed.at(0),1));
        }else{
            char a = typed.at(0);
            int con = 1;
            for(int i=1;i<len_typed;i++){
                if(a!=typed.at(i)){
                    v2.push_back(make_pair(a,con));
                    a = typed.at(i);
                    con =1;
                }else{
                    con++;
                }
            }
        }


        if(v1.size()!=v2.size())
            return false;
        for(int i=0;i<v1.size();i++){
            if(v1.at(i).first != v2.at(i).first)
                return false;
            if(v1.at(i).second > v2.at(i).second)
                return false;
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    string s1("alex");
    string s2("aaleex");
    cout << s.isLongPressedName(s1,s2)<< endl;;
	return 0;
}




