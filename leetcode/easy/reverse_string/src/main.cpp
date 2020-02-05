#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        if(size<2)
            return;
        int head = 0;
        int tail = size-1;
        char t;
        while(head<tail) {
            t = s.at(head);
            s.at(head) = s.at(tail);
            s.at(tail) = t;
            head++;
            tail--;
        }

    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




