#include <string.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head)
            return true;

        int len;
        std::vector<int> v;
        std::vector<int>::iterator it;
        std::vector<int>::reverse_iterator rit;
        ListNode* p=head;
        while(p)
        {
            v.push_back(p->val);
            p = p->next;
        }
        
        len = v.size();
        it = v.begin(),
        rit = v.rbegin();
        for(int i = 0;i < len/2;++it,++rit,++i)
        {
            if(*it != *rit)
                return false;
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
  printf("hello \r\n");
  Solution s;

  cout << s.isPalindrome(121) << endl;
  cout << s.isPalindrome(-121) << endl;
  cout << s.isPalindrome(1231) << endl;
  return 0;
}
