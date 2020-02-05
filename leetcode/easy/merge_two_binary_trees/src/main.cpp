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
    void merge(TreeNode* t1,TreeNode* t2,TreeNode** m) {
        if(t1==NULL && t2==NULL) {
            *m = NULL;
            return;
        }else if(t1!=NULL && t2==NULL) {
            (*m)->val = t1->val;
            *m = t1;
        }else if(t1==NULL && t2!=NULL) {
            (*m)->val = t2->val;
            *m = t2;
        }else {
            (*m)->val = t1->val + t2->val;
            TreeNode* le = new TreeNode(0);
            (*m)->left = le;
            merge(t1->left,t2->left,&((*m)->left));
            TreeNode* ri = new TreeNode(0);
            (*m)->right = ri;
            merge(t1->right,t2->right,&((*m)->right));
        }

    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* r = new TreeNode(0);
        merge(t1,t2,&r);
        return r;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




