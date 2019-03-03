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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
	public:
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			ListNode* pl1;
			ListNode* pl2;
			if((l1 == NULL)||(l2 == NULL))
			{
				if(l1)
					return l1;
				if(l2)
					return l2;
				else
					return NULL;
			}

			pl1 = l1;
			pl2 = l2;
			ListNode* head = NULL;
			ListNode** pn = NULL;
			bool store = true;
			while(pl1 || pl2)
			{
				ListNode* plist = new ListNode(0);
				if(pn)
					*pn = plist;
				if(store)
				{
					head = plist;
					store = false;
				}
				if(pl1 && pl2)
				{
					if(pl1->val < pl2->val)
					{
						plist->val = pl1->val;
						pl1 = pl1->next;
					}
					else
					{
						plist->val = pl2->val;
						pl2 = pl2->next;
					}
				}
				else
				{
					if(pl1)
					{
						plist->val = pl1->val;
						pl1 = pl1->next;
					}
					if(pl2)
					{
						plist->val = pl2->val;
						pl2 = pl2->next;
					}
				}
				pn = &(plist->next);
			}
			return head;
		}
};

int main(int argc, char* argv[])
{
	ListNode* res;
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(1);
	ListNode f(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	e.next = &f;
	Solution s;
	res = s.mergeTwoLists(&a,&e);
	while(res)
	{
		cout << res->val << endl;
		res = res->next;
	}
	return 0;
}




