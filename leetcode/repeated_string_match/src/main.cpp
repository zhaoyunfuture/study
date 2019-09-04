#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool match(string& A, string& B ,int index) {
        int lenA = A.length();
        int lenB = B.length();
        int len = (lenA-index)<lenB?(lenA-index):lenB;
        int j=0;
        int k=index;
        for(int i=0;i<len;i++) {
            if(A.at(k)!=B.at(j))
                return false;
            else{
                k++;
                j++;
            }
        }
        return true;
    }
    bool firstmatch(string& A, string& B,int& index) {
        int lenA = A.length();
        int lenB = B.length();

        for(int i=0;i<lenA;++i) {
            if(match(A,B,i)){
                index = i;
                return true; 
            }
        }
        return false;
    }
    int repeatTime(string& A, string& B,int in) {
        int lenA = A.length();
        int lenB = B.length();
        int repeat = 1;
        int index = in;
        for(int i=0;i<lenB;++i) {
            if(index == lenA){
                index = 0;
                repeat++;
            }
            if(A.at(index)!=B.at(i))
                return -1;
            else
                index++;
        }
        return repeat;
    }
    int repeatedStringMatch(string A, string B) {        
        int index = 0;
        if(!firstmatch(A,B,index))
            return -1;
        cout <<"index:" << index << endl;
        int repeat = repeatTime(A,B,index);
        if(repeat != -1)
            return repeat;
        else{
            if(index != A.length()-1)
                return repeatTime(A,B,index+1);
            else 
                return -1;
        }
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




