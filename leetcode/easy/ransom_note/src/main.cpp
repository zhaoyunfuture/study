#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int r_size = ransomNote.size();
        int m_size = magazine.size();
        int t=0;
        bool flag = true;
        if(r_size>m_size)
            return false;
        for(int i =0;i<m_size;){
            flag = true;
            if(r_size>(m_size-i))
                return false;
            t = 0;
            while(t<r_size){
                if(ransomNote.at(t) == magazine.at(i)){
                    i++;
                    t++;
                }else {
                    flag = false;
                    i++;
                    break;
                }
            }
            if(flag)
                break;
            else {
                if(i==m_size)
                    return false;
            }
        }
        return true;

    }
};

int main(int argc, char* argv[])
{
    Solution s;
    cout << s.canConstruct("bg","efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj") << endl;
	return 0;
}



