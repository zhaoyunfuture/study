#include <string.h>
#include <string>
#include <iostream>
using namespace std;
#if 0
class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = -1;
        int len = haystack.size();
        int num = needle.size();
        if ((len == 0 && num == 0)||(num==0)) return 0;
        if(len==0) return -1;
        bool fullmatch = false;
        for (int i = 0; i < len - num +1; i++)
        {
            if (haystack[i] == needle[0])
            {//比第一个数
                fullmatch = true;
                for (int j = 1; j < num; j++)
                {//比余下的数
                    if (haystack[i + j] != needle[j])
                    {
                        fullmatch = false;
                        break;
                    }
                    else
                    {
                        fullmatch = true;
                    }
                }
                if (fullmatch)
                {//全部都符合，返回索引
                    index = i;
                    return index;
                }
            }
        }
        return index;
    }
};
#endif
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;

        if(haystack == "")
            return -1;
        
        std::size_t found = haystack.find(needle);
        if(found != std::string::npos)
            return found;
        else
            return -1;
    }
};

int main(int argc, char* argv[])
{
    std::string str ("There are two needles in this haystack with needles.");
    std::string str2 ("needle");
    Solution s;
    cout << s.strStr(str,str2) << endl;
	return 0;
}




