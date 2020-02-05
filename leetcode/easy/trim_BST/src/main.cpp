#include <string.h>
#include <string>
#include <iostream>
using namespace std;

/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */

class Solution {
public:
    TreeNode* head= NULL;
    bool ishead = true;
    void trim(TreeNode* r,TreeNode** o,int L,int R) {
        TreeNode* t = NULL;
        if(r == NULL)
            return ;
        if(r->val<L || r->val>R){
            trim(r->left,o,L,R);
            trim(r->right,o,L,R);
        }
        else {
            t = new TreeNode(r->val);
            if(ishead){
                head = t;
                ishead =false;
            }
            if(o)
                *o = t;
            trim(r->left,&(t->left),L,R);
            trim(r->right,&(t->right),L,R);
        }       
    }
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        trim(root,NULL,L,R);
        return head;
    }
};


int main(int argc, char* argv[])
{
  
	return 0;
}




