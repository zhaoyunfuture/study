#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    size_t find(string s, int index,bool f2e,bool &f) {
        size_t found;
        if(f2e) {
            for (unsigned i=index; i<s.length(); ++i) {
                found = vowels.find(s.at(i));
                if(found != std::string::npos) {
                    f = true;
                    return i;
                }            
            }
            f = false;
            return 0;
        }else {
            for (unsigned j=index; j>=0; --j) {
                found = vowels.find(s.at(j));
                if(found != std::string::npos) {
                    f = true;
                    return j;
                }
            }
            f = false;
            return 0;
        }
    }
    string reverseVowels(string str) {
        string s = str;
        int size = s.size();
        if(size<2)
            return s;
        int head = 0;
        int tail = size-1;
        char t;
        bool found = false;
        while(head<tail) {
            head = find(s,head,true,found);
            if(!found)
                break;
            tail = find(s,tail,false,found);
            if(!found)
                break;
            if(head>tail)
                break;
            t = s.at(head);
            s.at(head) = s.at(tail);
            s.at(tail) = t;
            head++;
            tail--;
        }
        return s;
    }
    string vowels = "aeiouAEIOU";
};

int main(int argc, char* argv[])
{
    Solution s;
    cout << s.reverseVowels("leetcode") << endl;
	return 0;
}




