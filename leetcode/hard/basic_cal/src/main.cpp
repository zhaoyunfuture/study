#include <string.h>
#include <string>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /* 0:+ ; 1:- */
    int process(vector<int>& num,vector<int>& addmin){
        cout << num.size() << " " << addmin.size() << endl;
        int out=0;
        if(addmin.size()==0)
            return num.at(0);
        for(int i=0;i<addmin.size();i++){
            if(i==0){
                if(addmin.at(i)==0)
                    out = num.at(0)+num.at(1);
                else
                    out = num.at(0)-num.at(1);
            }else{
                if(addmin.at(i)==0)
                    out += num.at(i+1);
                else
                    out -= num.at(i+1);
            }
        }
        return out;
    }
    int convert(string n){
        int len = n.length();
        int out=0;
        char zero = '0';
        for(int i=0;i<len;i++){
            out += (n.at(i)-zero)*pow(10,len-1-i);
        }
        return out;
    }
    int cal(string& s,int& index){
        vector<int> num;
        vector<int> addminus;
        string t;
        char space = ' ';
        char left_bracket = '(';
        char right_bracket = ')';
        //bool lastisnum = false;
        while(index<s.length()) {
            if(s.at(index)==left_bracket){
                index++;
                num.push_back(cal(s,index));
             
            }else if(s.at(index)==space){
                index++;
                if(!t.empty()){
                    num.push_back(convert(t));
                    t.clear();
                }  
            }else if(s.at(index)=='+'){
                addminus.push_back(0);
                index++;
                if(!t.empty()){
                    num.push_back(convert(t));
                    t.clear();
                } 
            }else if(s.at(index)=='-'){
                addminus.push_back(1);
                index++;
                if(!t.empty()){
                    num.push_back(convert(t));
                    t.clear();
                } 
            }else if(s.at(index)==right_bracket){
                index++;
                if(!t.empty()){
                    num.push_back(convert(t));
                    t.clear();
                }
                return process(num,addminus);
            }else{
                t.push_back(s.at(index));
                if(index==s.length()-1){
                    num.push_back(convert(t));
                }
                index++;
            }
        }
        return process(num,addminus);
    }
    int calculate(string s) {
        int len = s.length();
        if(len==0)
            return 0;
        int i=0;
        int out = cal(s,i);
        return out;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    string ss="1";
    cout << s.calculate(ss);
	return 0;
}




