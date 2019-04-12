#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> v;
        if(num == 0) {
            v.push_back("0:00");
            return v;
        }else if (num >8)
            return v;
        else {
            prepare_min();
            prepare_sec();
            for(int i=(num>=5?(num-5):0);i<=(num>3?3:num);++i){
                for(int j=0;j<min.at(i).size();++j){
                    for(int k=0;k<sec.at(num-i).size();++k){
                        string t=min.at(i).at(j);
                        t.append(sec.at(num-i).at(k));
                        v.push_back(t);
                    }
                }
            }
            return v;
        }
    }
    int count_one(int n) {
        int count = 0;
        while(n) {
            n = n&(n-1);
            count++;
        }
        return count;
    }
    void prepare_sec(){
        string s;
        vector<string>v;
        for(int j=0;j<6;++j){
            sec.insert(pair<int,vector<string>>(j,v));
        }
        for(int i=0;i<60;++i){
            if(i<10){
                s = to_string(i);
                s.insert(0,"0");
                it = sec.find(count_one(i));
                it->second.push_back(s);
            }else {
                s = to_string(i);
                it = sec.find(count_one(i));
                it->second.push_back(s);
            }
        }
    }
    void prepare_min() {
        string s;
        vector<string>v;
        for(int j=0;j<4;++j){
            min.insert(pair<int,vector<string>>(j,v));
        }
        for(int i=0;i<12;++i){
            s = to_string(i);
            s.append(":");
            it = min.find(count_one(i));
            it->second.push_back(s);
        }
    }
    map<int,vector<string>> sec;
    map<int,vector<string>> min;
    map<int,vector<string>>::iterator it;
};

int main(int argc, char* argv[])
{
    Solution s;
    /*s.prepare_min();
    for(int i=0;i<s.min.size();++i){
        for(int j=0;j<s.min.at(i).size();++j)
        {
            cout << s.min.at(i).at(j) << " ";
        }
        cout << endl;
    }
    */
    vector<string> v;
    v = s.readBinaryWatch(6);
    for(int j=0;j<v.size();++j)
        cout << v.at(j) << " "; 
    cout << endl;
	return 0;
}

 


