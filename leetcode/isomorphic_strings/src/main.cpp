#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> style(string s) {
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
    bool isIsomorphic(string s, string t) {
        vector<int> a;
        vector<int> b;
        a = style(s);
        b = style(t);
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
    vector<int> a;
    a = s.style("paper");
    for(int i=0;i<a.size();++i)
    {
        cout << a.at(i) << ' ';
    }
    cout << endl;
    cout << s.isIsomorphic("paper","title") << endl;
	return 0;
}




