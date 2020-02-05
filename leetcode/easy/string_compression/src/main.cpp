#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int size = chars.size();
        if(size < 2)
            return size;
        char prev = chars.at(0);
        int index = 1;
        int num = 1;
        string con;
        for(int i=1;i<size;++i){
            if(prev == chars.at(i)){
                num++;
            }else{
                if(num>1){
                    con = to_string(num);                    
                    for(int j=0;j<con.size();++j){
                        chars.at(index+j) = con.at(j);
                    }
                    chars.at(index+con.size()) = chars.at(i);
                    index += con.size()+1;
                    num = 1;
                }else{
                    chars.at(index) = chars.at(i);
                    index++;
                }                
                prev = chars.at(i);
            }
        }
        if(num>1){
            con = to_string(num);                    
            for(int k=0;k<con.size();++k){
                chars.at(index+k) = con.at(k);
            }
            index += con.size();
        }
        while(index < size){
            chars.pop_back();
            index++;
        }
        return chars.size();
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




