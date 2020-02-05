#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class RecentCounter {
public:
    vector<unsigned int> cont;
    RecentCounter() {
        cont.clear();
    }

    int ping(int t) {
        if(cont.size()==0){
            cont.push_back(t);
            return 1;
        }else{
            int res = 1;
            int target;
            if(t<3000)
                target = 0;
            else
                target = t-3000;
            for(int i=0;i<cont.size();i++){
                if(cont.at(i)>=target)
                    res++;
                else
                    break;
            }
            cont.insert(cont.begin(),t);
            return res;
        }
    }
};

/**
 *  * Your RecentCounter object will be instantiated and called as such:
 *   * RecentCounter* obj = new RecentCounter();
 *    * int param_1 = obj->ping(t);
 *     */
int main(int argc, char* argv[])
{
  
	return 0;
}




