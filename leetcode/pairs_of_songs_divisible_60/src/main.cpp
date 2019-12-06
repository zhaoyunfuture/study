#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0;
        map<int, int> arr;
        for(int i = 0; i < time.size(); i++) {
            time[i] %= 60;
            arr[time[i]]++;
        }
        for(auto it = arr.begin(); it != arr.end(); it++) {
            if((it->first == 30) || (it->first == 0))
                res += it->second * (it->second - 1) / 2;
            else if(arr[60 - it->first] > 0) {
                res += it->second*arr[60 - it->first];
                arr.erase(60 - it->first);
            }    
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




