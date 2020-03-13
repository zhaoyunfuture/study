#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int cont=0;
    void findnext(int idx_t,int idx_s,string& s,string& t) {
        for(int i=idx_s;i<s.length();i++) {
            if(t.at(idx_t)==s.at(i)) {
                if(idx_t==t.length()-1){
                    cont++;                    
                    cout << cont << endl;
                }else{
                    findnext(idx_t+1,i+1,s,t);
                }                
            }
        }      
    }
    int numDistinct(string s, string t) {
        int lens = s.length();
        int lent = t.length();
        if(lens==0 || lent==0){
            return 0;
        }
        
        findnext(0,0,s,t);
        cout << cont << endl;
        return cont;
    }
};
int main(int argc, char* argv[])
{
    Solution s;
    //string ss="adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc";
    string ss="adbdadeecadeadeccaeaabdabdbdaaeeeeedaacadbdcceeabddaddacdddbc";
    string t="bcddceeeebecbc";
    cout << s.numDistinct(ss,t);

	return 0;
}




