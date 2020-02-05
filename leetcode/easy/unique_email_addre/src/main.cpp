#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string preprocess(string s){
        string out;
        size_t found = s.find('@');
        string domain ( s,found,s.length()-found);        
        string local (s.begin(),s.begin()+found);

        found = local.find_first_of('+');
        string woplus;
        if (found!=std::string::npos)
            woplus.assign(local.begin(),local.begin()+found);
        else
            woplus = local;

        for(int i=0;i<woplus.length();i++){
            if(woplus.at(i)=='.')
                continue;
            else
                out.push_back(woplus.at(i));
        }       
        out.append(domain);        
        return out;
    }
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        set<string>::iterator sit;
        for(int i=0;i<emails.size();i++){
            string p = preprocess(emails.at(i));
            sit = s.find(p);
            if(sit==s.end())
                s.insert(p);
        }
        return s.size();
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




