#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        if(size==0)
            return false;
        if(size==1)
            return flowerbed.at(0)==0?true:n==0?true:false;
        int max = 0;
        int tmp = 0;
        int head = 0;
        int head_max = 0;
        int tail = size;
        int tail_max = 0;
        bool found = false;
        bool isempty_head = flowerbed.at(0) == 0 ? true:false;
        if(isempty_head){
            for(int i=1;i<size;++i) {
                if(flowerbed.at(i) == 1){
                    head = i+1;
                    head_max = i/2;
                    found = true;
                    break;
                }
            }
            if(!found)
                return ((size+1)/2) >= n;
        }
        bool isempty_tail = flowerbed.at(size-1) == 0 ? true:false;
        if(isempty_tail){
            for(int i=size-1;i>=0;--i) {
                if(flowerbed.at(i) == 1){
                    tail = i+1;
                    tail_max = (size-i-1)/2;
                    break;
                }
            }
        }

        for(int i=head;i<tail;++i) {
            if(flowerbed.at(i)==0)
                tmp++;
            else {
                if(tmp==0)
                    continue;
                max += (tmp-1)/2;
                tmp = 0;
            }
        }
        cout << max << head_max << tail_max << endl;
        if( (max+head_max+tail_max) >=n )
            return true; 
        else
            return false;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




