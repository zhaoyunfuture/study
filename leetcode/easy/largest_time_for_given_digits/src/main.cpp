#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:    
    void cont_min(int h1,int h2,vector<int>& A,vector<vector<int>>& validtime){        
        int min1,min2,min3,min4;
        int min_max;
        int hou;
        bool first = false;
        for(int i=0;i<4;i++){
            if(i!=h1 && i!=h2 && !first){
                min1 = A.at(i);
                first = true;
            }else if(i!=h1 && i!=h2 && first){
                min2 = A.at(i);
            }                
        }
        min3 = min1*10+min2;
        min4 = min2*10+min1;
        if(min3>59 && min4>59)
            return;
        else{            
            if(min3<60 && min4<60){
                if(min3>min4)
                    min_max = min3;
                else
                    min_max = min4;
            }else if(min3<60)
                min_max = min3;
            else if(min4<60)
                min_max = min4;            
        }
        hou = A.at(h1)*10+A.at(h2);
        vector<int> v;
        v.push_back(hou);
        v.push_back(min_max);
        validtime.push_back(v);        
    }
    void output(int h,int m,string& time){
        if(h==0)
            time.append("00");
        else if(h<10){
            time.push_back('0');
            time.append(to_string(h));
        }
        else
            time = to_string(h);
        time.push_back(':');
        if(m==0)
            time.append("00");
        else if(m<10){
            time.push_back('0');
            time.append(to_string(m));
        }else
            time.append(to_string(m));
    }
    string largestTimeFromDigits(vector<int>& A) {
        string time;
        vector<vector<int>> validtime;
        for(int i=0;i<3;i++){
            for(int j=i+1;j<4;j++){
                if(A.at(i)==A.at(j)){
                    int hou = A.at(i)*10+A.at(j);
                    if(hou<24 ){
                        cont_min(i,j,A,validtime);
                    }
                }else{
                    int hou1 = A.at(i)*10+A.at(j);
                    int hou2 = A.at(j)*10+A.at(i);
                    if(hou1>23 && hou2>23)
                        continue;
                    else{        
                        if(hou2<24)
                            cont_min(j,i,A,validtime);
                        if(hou1<24)
                            cont_min(i,j,A,validtime);
                    }
                }
            }
        }
        cout << validtime.size()<<endl;
        for(int i=0;i<validtime.size();i++){
            cout << validtime.at(i).at(0) << ' ' <<validtime.at(i).at(1)<< endl;
        }
        if(validtime.size()==0)
            return time;
        else{
            int max_h=validtime.at(0).at(0);
            int max_m=validtime.at(0).at(1);
            if(validtime.size()==1){
                output(max_h,max_m,time);
                return time;
            }else{
                for(int i=1;i<validtime.size();i++){
                    if(max_h<validtime.at(i).at(0)){
                        max_h = validtime.at(i).at(0);
                        max_m = validtime.at(i).at(1);
                    }
                }
                output(max_h,max_m,time);
                return time;
            }
        }
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




