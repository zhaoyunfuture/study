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
		ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
			if((headA == NULL)||(headB==NULL))
				return NULL;

			if(headA == headB)
				return headA;

			vector<ListNode *> a;
			vector<ListNode *> b;
			ListNode* pa=headA;
			ListNode* pb=headB;
			while(pa)
			{
				a.push_back(pa);
				pa = pa->next;
			}
			while(pb)
			{
				b.push_back(pb);
				pb = pb->next;
			}
			vector<ListNode *>::reverse_iterator rita = a.rbegin();
			vector<ListNode *>::reverse_iterator ritb = b.rbegin();
			bool first = true;
			for(;(rita!=a.rend())&&(ritb!=b.rend());rita++,ritb++)
			{
				if((*rita != *ritb) && first)
					return NULL;
				else if(*rita == *ritb)
				{
					first = false;
					if((ritb+1 == b.rend())||(rita+1 == a.rend()))
						return *(rita);
					else
						continue;
				}
				else if((*rita != *ritb) && !first)
					return *(--rita);              
			}

			return NULL;

		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




