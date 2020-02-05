#include <string.h>
#include <string>
#include <iostream>
using namespace std;

/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     ListNode *next;
 **     ListNode(int x) : val(x), next(NULL) {}
 ** };
 *
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* t;
        ListNode* p;
        int v;
        if (head != NULL)
        {
            v = head->val;
            p = head;
            t = head->next;
            while(t)
            {
                if(v == t->val)
                {
                    t = t->next;
                    if(t == NULL)
                        p->next = NULL;
                }
                else
                {
                    v = t->val;
                    p->next = t;
                    p = t;
                    t = t->next;
                }
            }
            return head;
        }
        else
            return NULL;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    ListNode* res; 
    ListNode a(1); 
    ListNode b(1); 
    ListNode c(2); 
    ListNode d(3);
    ListNode e(3);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;

    res = s.deleteDuplicates(&a);
    while(res)
    {
        cout <<res->val << endl;
        res = res->next;
    }
	return 0;
}




