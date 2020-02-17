#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
    public:
        bool lowSummit(vector<int>& summit,vector<int>& height,int& pos){
            for(int i=1;i<summit.size()-1;i++){
                if(height.at(summit.at(i))<=height.at(summit.at(i-1))&&
                        height.at(summit.at(i))<=height.at(summit.at(i+1))){
                    pos = i;                
                    return true;

                }

            }
            return false;

        }
        int waterInSlot(int start,int end,vector<int>& height){
            int water=0;
            int waterLine=height.at(start)>height.at(end)?height.at(end):height.at(start);
            for(int i=start+1;i<end;i++){
                if(waterLine>height.at(i))
                    water += (waterLine-height.at(i));

            }        
            return water;

        }
        int trap(vector<int>& height) {
            int len = height.size();
            if(len<3)
                return 0;
            int water = 0;
            vector<int> summit;
            int first=0;
            while(first<len && height.at(first)<=height.at(first+1)){            
                first++;
                if(first>=len-1)
                    return 0;

            }
            if(first>=len)
                return 0;
            summit.push_back(first);
            for(int i=1;i<len-1;i++){
                if( (height.at(i)>height.at(i-1)&&height.at(i)>=height.at(i+1))||
                        (height.at(i)>=height.at(i-1)&&height.at(i)>height.at(i+1))
                  )
                    summit.push_back(i);

            }
            if(height.at(len-1)>height.at(len-2)){
                summit.push_back(len-1);

            }
#if 0
            cout <<"before "<<summit.size() << endl;
            for(int i=0;i<summit.size();i++){
                cout << summit.at(i) << ' ';

            }
#endif
            if(summit.size()<2)
                return 0;
            int pos = -1;
            while(summit.size()>2){
                if(lowSummit(summit,height<Plug>PeepOpenos))
                    summit.erase(summit.begin()+pos);
                else
                    break;

            }
#if 0
            cout <<"after " <<summit.size() << endl;
            for(int i=0;i<summit.size();i++){
                cout << summit.at(i) << ' ';

            }
#endif
            if(summit.size()==2){
                return waterInSlot(summit.at(0),summit.at(1),height);

            }
            for(int i=0;i<summit.size()-1;i++){
                water += waterInSlot(summit.at(i),summit.at(i+1),height);

            }
            return water;

        }

};

int main(int argc, char* argv[])
{
  
	return 0;
}




