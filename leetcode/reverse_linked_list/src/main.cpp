#include <string.h>
#include <string>
#include <iostream>
using namespace std;

/**
 ** Definition for singly-linked list.
 *
 **/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = NULL;
        ListNode* n = NULL;
        ListNode* t = NULL;
        if(head == NULL)
            return NULL;
        p = head;
        n = head->next;
        head->next = NULL;
        while(n) {
            t = n->next;
            n->next = p;
            p = n;
            n = t;
        } 
        return p;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




