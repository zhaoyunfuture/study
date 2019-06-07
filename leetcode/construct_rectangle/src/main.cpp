#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> r;
        double root = sqrt(area);
        int ro = (int) floor(root);
        int w = ro;
        int l = w+1;
        if (w*w == area) {
            r.push_back(w);
            r.push_back(w);
        }
        else {
            while (1) {
                if(w*l == area) {
                    r.push_back(l);
                    r.push_back(w);
                    break;
                }
                else if (w*l < area) {
                    l++;
                }else {
                    w--;
                    l = ro;
                }
            }
        }            
        return r;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




