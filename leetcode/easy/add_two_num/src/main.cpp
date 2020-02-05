#include <string.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <math.h>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        unsigned int i,a,b,r,t;
	bool flag=true;
	ListNode* tmp,*res,*head,*p;
	tmp = l1;
	i = 0;
	a = 0;
	b = 0;
	while(tmp != NULL){
	  a += tmp->val * pow(10,i);
	  i++;
	  tmp = tmp->next;
	}

	i = 0;
	tmp = l2;
	while(tmp != NULL){
	  b += tmp->val * pow(10,i);
	  i++;
	  tmp = tmp->next;
	}

	r = a + b;
	printf("a:%d , b:%d, sum:%d\r\n",a,b,r);
	t = r;
	p = NULL;
	while( !((t%10 == 0) && (t/10%10 == 0)) ){
          res = new ListNode(t%10);
	  printf("%d \r\n",res->val);
	  if(flag){
	    head = res;
	    flag = false;
	  }
	  if(p != NULL)
	    p->next = res;
	  p = res;
	  t = t/10;
	}
	return head;
    }
};

int main(int argc, char* argv[])
{
  printf("hello \r\n");
  ListNode a(2),b(4),c(3),d(5),e(6),f(4),*r;
  a.next = &b;
  b.next = &c;
  d.next = &e;
  e.next = &f;
  
  Solution s;
  r = s.addTwoNumbers(&a,&d);
  while(r != NULL)
  {
    printf("%d\r\n",r->val);
    r = r->next;
  }
  return 0;
}
