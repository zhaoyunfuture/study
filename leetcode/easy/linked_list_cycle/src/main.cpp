#include <string.h>
#include <string>
#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	public:
		bool hasCycle(ListNode *head) {
			if((head == NULL) || (head->next == NULL))
			{
				return false;
			}
			ListNode* p1 = head;
			ListNode* p2 = head->next->next;
			while(p1 && p2)
			{
				if(p1 == p2)
					return true;
				p1 = p1->next;
				if(p2->next==NULL)
					return false;
				else
					p2 = p2->next->next;
			}
			return false;
		}
																																																   };
int main(int argc, char* argv[])
{
  
	return 0;
}




