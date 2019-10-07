#include <string.h>
#include <string>
#include <iostream>
using namespace std;


class Solution {
	public:
		int uniqueMorseRepresentations(vector<string>& words) {
			string code[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
			set<string> s;
			set<string>::iterator sit;
			string str;
			for(int i=0;i<words.size();++i) {
				str.clear();
				for(int j=0;j<words.at(i).size();++j){
					int t = words.at(i).at(j) - 'a';
					str.append(code[t]);
				}
				sit = s.find(str);
				if(sit == s.end())
					s.insert(str);
			}
			return s.size();
		}
};
int main(int argc, char* argv[])
{
  
	return 0;
}




