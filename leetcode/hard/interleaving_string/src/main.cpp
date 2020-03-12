#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isinter(string s1,string s2,int i,string& s3){
        if(i==s3.length())
            return true;
        if(s1.length()==0){
            if(s2.at(0)==s3.at(i)){
                string t;
                if(s2.length()>1){
                    t = s2.substr(1,s2.length()-1);                      
                }
                return isinter(s1,t,i+1,s3);
            }else
                return false;
        }
        if(s2.length()==0){
            if(s1.at(0)==s3.at(i)){
                string t;
                if(s1.length()>1){
                    t = s1.substr(1,s1.length()-1);
                }
                return isinter(t,s2,i+1,s3);
            }else
                return false;
        }

        if(s1.at(0)==s3.at(i) && s2.at(0)==s3.at(i)){
            string t1;
            string t2;
            bool res1;
            bool res2;
            if(s1.length()>1)
                t1 = s1.substr(1,s1.length()-1);
            if(s2.length()>1)
                t2 = s2.substr(1,s2.length()-1);
            res1 = isinter(t1,s2,i+1,s3);
            res2 = isinter(s1,t2,i+1,s3);
            return res1||res2;
        }else if(s1.at(0)!=s3.at(i) && s2.at(0)==s3.at(i)){
            string t;
            if(s2.length()>1)
                t = s2.substr(1,s2.length()-1);
            return isinter(s1,t,i+1,s3);
        }else if(s1.at(0)==s3.at(i) && s2.at(0)!=s3.at(i)){
            string t;
            if(s1.length()>1)
                t = s1.substr(1,s1.length()-1);
            return isinter(t,s2,i+1,s3);
        }else
            return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int lens1 = s1.length();
        int lens2 = s2.length();
        int lens3 = s3.length();
        if(lens1+lens2 != lens3)
            return false;
        if(lens1 == 0 || lens2 ==0) {
            if(lens1 == 0){
                if(s2==s3)
                    return true;
                else
                    return false;
            }else{
                if(s1==s3)
                    return true;
                else
                    return false;
            }
        }
        return isinter(s1,s2,0,s3);
    }
};
int main(int argc, char* argv[])
{
    Solution s;
    string s1="aabcc";
    string s2="dbbca";
    string s3="aadbbcbcac";
    cout << s.isInterleave(s1,s2,s3) << endl;
	return 0;
}




