#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            map<vector<int>,int> m;
            map<vector<int>,int>::iterator mit;
            vector<int> tmp;
            for(int i=0;i<dominoes.size();i++){
                tmp.clear();
                if(dominoes.at(i).at(0)>dominoes.at(i).at(1)){
                    tmp.push_back(dominoes.at(i).at(1));
                    tmp.push_back(dominoes.at(i).at(0));

                }else{
                    tmp.push_back(dominoes.at(i).at(0));
                    tmp.push_back(dominoes.at(i).at(1));

                }
                mit = m.find(tmp);
                if(mit == m.end()){
                    m.insert(pair<vector<int>,int>(tmp,1));

                }else{
                    mit->second++;

                }

            }
            int cont=0;

            for(mit=m.begin();mit!=m.end();mit++){

                if(mit->second!=1){
                    if(mit->second==2)
                        cont++;
                    else{
                        int t = mit->second;
                        cont += t*(t-1)/2;

                    }

                }

            }
            return cont;

        }

};
int main(int argc, char* argv[])
{
  
	return 0;
}




