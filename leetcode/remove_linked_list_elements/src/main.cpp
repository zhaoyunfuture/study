#include <string.h>
#include <string>
#include <iostream>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return NULL;
        ListNode* prev = head;
        ListNode* next = NULL;
        while(prev->val == val) {
            head = prev->next;
            if(!head) {
                next = NULL;
                break;
            }
            else {
                prev = head;
            }
        }
        if (head)
            next = head->next;
        while(next) {
            if(next->val == val) {
                prev->next = next->next;                             
                next = next->next;                
            }
            else {
                prev = next;
                next = next->next;
            }
        }
        return head;
    }
};
int main(int argc, char* argv[])
{
  
	return 0;
}




