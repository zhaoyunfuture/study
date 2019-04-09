#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pattern_word(vector<string> s) {
        map <string, int> m;
        map<string,int>::iterator mit;
        vector<int> r;
        int num = 0;
        for ( vector<string>::iterator it=s.begin(); it!=s.end(); ++it)
        {
            mit = m.find(*it);
            if(mit == m.end())
            {
                m.insert(pair<string,int>(*it,num));
                r.push_back(num);
                num++;
            }
            else
            {
                r.push_back(mit->second);
            }
        }
        return r;
    }

    vector<int> pattern_letter(string s) {
        map <char, int> m;
        map<char,int>::iterator mit;
        vector<int> r;
        int num = 0;
        char c;
        for ( string::iterator it=s.begin(); it!=s.end(); ++it)
        {
            c = *it;
            mit = m.find(c);
            if(mit == m.end())
            {
                m.insert(pair<char,int>(c,num));
                r.push_back(num);
                num++;
            }
            else
            {
                r.push_back(mit->second);
            }
        }
        return r;
    }
    vector<string> str_word(string s) {
        vector<string> v;
        string str = s;
        std::size_t found = str.find_first_of(" ");
        while (found!=std::string::npos) {
            v.push_back(str.substr(0,found));
            str = str.substr(found+1);
            found = str.find_first_of(" ");
        }
        if(!str.empty())
            v.push_back(str);
        return v;
    }
    bool wordPattern(string pattern, string str) {
        vector<int> a;
        vector<int> b;
        vector<string> s;
        s = str_word(str);
        a = pattern_letter(pattern);
        b = pattern_word(s);
        if(a.size() != b.size())
            return false;
        for(int i=0;i<a.size();++i)
        {
            if(a.at(i) != b.at(i))
                return false;
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<string> a;
    a = s.str_word("paper rock scissor");
    for(int i=0;i<a.size();++i)
    {
        cout << a.at(i) << ' ';
    }
    cout << endl;
    cout << s.wordPattern("abc","paper rock scissor");
	return 0;
}




