#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        void reverse(vector<ListNode*>& v,ListNode** head,ListNode** tail){
            *head = v.at(v.size()-1);
            *tail = v.at(0);
            for(int i=v.size()-1;i>0;i--){
                v.at(i)->next = v.at(i-1);
            }
            (*tail)->next = NULL;
        }
        ListNode* reverseKGroup(ListNode* head, int k) {
            if(head==NULL)
                return NULL;
            vector<ListNode*> v;
            int num = 0;        
            ListNode* t = head;
            //ListNode* lasth = NULL;
            ListNode* lastt = NULL;
            ListNode* curh = NULL;
            ListNode* curt = NULL;
            ListNode* out = NULL;
            bool first = true;
            while(t!=NULL){
                v.push_back(t);
                t = t->next;
                ++num;
                if(num==k){
                    lastt = curt;
                    reverse(v,&curh,&curt);
                    if(first){
                        out = curh;
                        first = false;
                    }
                    num = 0;                
                    v.clear();
                }
                if(num==0){
                    if(lastt!=NULL)
                        lastt->next = curh;
                    lastt = curt;
                }
            }
            if(first)
                return head;
            if(num!=0){
                curt->next = v.at(0);
            }
            return out;        
        }
};

int main(int argc, char* argv[])
{
    Solution s;
    ListNode* out;
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    out = l1;
    while(out!=NULL){
        cout << out->val << ' ';
        out = out->next;
    }
    out = s.reverseKGroup(l1,2);
#if 1 
    while(out!=NULL){
        cout << out->val << ' ';
        out = out->next;
    }
#endif
	return 0;
}




