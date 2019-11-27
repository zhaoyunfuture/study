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
    bool isUni(TreeNode* n,int val){
        if(n==NULL)
            return true;
        if(n->val != val)
            return false;
        if(!isUni(n->left,val))
            return false;
        if(!isUni(n->right,val))
            return false;
        return true;
    }
    bool isUnivalTree(TreeNode* root) {
        return isUni(root,root->val);
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




