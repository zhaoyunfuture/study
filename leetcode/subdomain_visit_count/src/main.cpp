#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    void putInMap(string s,map<string,int>& m) {
        int con;        
        map<string,int>::iterator mit;
        size_t found = s.find_first_of(" ");
        if(found==std::string::npos)
            return;

        string c(s.begin(),s.begin()+found);
        string domain(s.begin()+found+1,s.end());        
        con = stoi(c);
        mit = m.find(domain);
        if(mit != m.end()){
            mit->second += con;
        }else{
            m.insert(pair<string,int>(domain,con));
        }
        found = domain.find_first_of(".");
        string d = domain;
        while (found!=std::string::npos){
            string subdomain (d.begin()+found+1,d.end());            
            mit = m.find(subdomain);
            if(mit != m.end()){
                mit->second += con;
            }else{
                m.insert(pair<string,int>(subdomain,con));
            }
            d.assign(d.begin()+found+1,d.end());            
            found = d.find_first_of(".");
        }

    }
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string,int> m;
        map<string,int>::iterator mit;
        vector<string> v;
        string cpd;

        for(int i=0;i<cpdomains.size();++i)
            putInMap(cpdomains.at(i),m);

        for(mit=m.begin();mit!=m.end();mit++){            
            cpd.clear();
            cpd.append(to_string(mit->second));
            cpd.append(" ");
            cpd.append(mit->first);
            v.push_back(cpd);
        }
        return v;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




