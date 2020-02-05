#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int move[4] = {0};
        for(int i=0;i<moves.length();++i) {
            char t = moves.at(i);
            switch (t) {
            case 'U': move[0] += 1;
                      break;
            case 'D': move[1] += 1;
                      break;
            case 'L': move[2] += 1;
                      break;
            case 'R': move[3] += 1;
                      break;
            default:
                      break;
            }
        }
        if(move[0] == move[1]&& move[2]==move[3])
            return true;
        else
            return false;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




