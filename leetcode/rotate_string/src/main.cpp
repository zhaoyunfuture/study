#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string shift(string a,int index) {
        string t(a.begin()+index,a.end());
        t.append(a.begin(),a.begin()+index);
        return t;
    }
    bool rotateString(string A, string B) {
        int sizea = A.length();
        int sizeb = B.length();
        if(sizea != sizeb)
            return false;
        if(A.compare(B) == 0)
            return true;
        string t;
        for(int i=1;i<sizea;i++){
            t = shift(A,i);
            if(t.compare(B) == 0)
                return true;
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




