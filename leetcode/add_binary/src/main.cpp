#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
        void add(int &i,int &j,string a,string b,string &s,bool &income)
        {
            if(a.at(i) != b.at(j))
            {
                if(income)
                {
                    s.insert(0,"0");
                    income = true;
                }
                else
                {
                    s.insert(0,"1");
                    income = false;
                }
            }
            else 
            {
                if(a.at(i)=='0')
                {
                    if(income)
                        s.insert(0,"1");
                    else
                        s.insert(0,"0");
                    income = false;
                }
                else// if(a.at(i)=='1')
                {
                    if(income)
                        s.insert(0,"1");
                    else
                        s.insert(0,"0");
                    income = true; 
                }
            }
        }

        void add1(int &j,string b,bool &income,string &s)
        {
            if(income)
            {
                if(b.at(j) == '1')
                {
                    if(j == 0)
                    {
                        s.insert(0,"0");
                        s.insert(0,"1");
                    }
                    else
                    {
                        s.insert(0,"0");
                        income = true;
                    }
                }
                else
                {
                    s.insert(0,"1");
                    income = false;
                }
            }
            else
            {
                if(b.at(j) == '1')
                    s.insert(0,"1");
                else
                    s.insert(0,"0");
                income = false;
            }
            j--;
        }
        string addBinary(string a, string b) {
            int len_a = a.length();
            int len_b = b.length();
            int i = len_a-1;
            int j = len_b-1;
            string s;
            bool income = false;
            while((i >= 0)||(j >= 0))
            {
                if((i == 0)&&(j == 0))
                {
                    if(a.at(i) != b.at(j))
                    {
                        if(income)
                        {
                            s.insert(0,"0");
                            s.insert(0,"1");
                        }
                        else
                            s.insert(0,"1");
                    }
                    else
                    {
                        if(a.at(i)== '0')
                        {
                            if(income)
                                s.insert(0,"1");
                            else
                                s.insert(0,"0");
                        }
                        else //if(a.at(i) == '1')
                        {
                            if(income)
                            {
                                s.insert(0,"1");
                                s.insert(0,"1");
                            }
                            else
                            {
                                s.insert(0,"0");
                                s.insert(0,"1");
                            }
                        }
                    }
                    break;
                }
                else if((i<0)||(j<0))
                {
                    if(i==-1)
                        add1(j,b,income,s);
                    else if(j==-1)
                        add1(i,a,income,s);
                }
                else
                {
                    add(i,j,a,b,s,income);
                    i--;j--;
                }
            }
            return s;
        }
};

int main(int argc, char* argv[])
{
    Solution s;
    //cout << s.addBinary("100","1") << endl;
    cout << s.addBinary("11","1") << endl;
    cout << s.addBinary("101","1") << endl;
    cout << s.addBinary("1010","1011") << endl;
    cout << s.addBinary("100","100") << endl;
	return 0;
}




