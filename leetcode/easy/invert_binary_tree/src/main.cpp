#include <string.h>
#include <string>
#include <iostream>
using namespace std;

/**
 *  * Definition for a binary tree node.
 * * struct TreeNode {
 * *     int val;
 * *     TreeNode *left;
 * *     TreeNode *right;
 * *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * * };
 * */
class Solution {
public:
    void swap(TreeNode* a,TreeNode* b) {
        int t;
        t = a->val;
        a->val = b->val;
        b->val = t;        
    }
    void invert(TreeNode* a,TreeNode* b,TreeNode* ap,TreeNode* bp,bool left) {
        if(a==NULL && b==NULL)
            return;
        if(a==NULL || b==NULL) {
            if(a==NULL) {
                if(left) {
                    ap->left = b;
                    bp->right = NULL;
                }else {
                    ap->right = b;
                    bp->left = NULL;
                }    
                invert(b->left,b->right,b,b,1);
            }else {
                if(left) {
                    ap->left = NULL;
                    bp->right = a;
                }else {
                    ap->right = NULL;
                    bp->left = a;
                } 
                invert(a->left,a->right,a,a,1);
            }
            return;
        }            
        swap(a,b);
        invert(a->left,b->right,a,b,1);
        invert(a->right,b->left,a,b,0);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        invert(root->left,root->right,root,root,1);
        return root;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




