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
    int sum(TreeNode* n) {        
        if(!n)
            return 0;
        int l = sum(n->left);
        int r = sum(n->right);
        return l+r+n->val;
    }
    int aNodeTilt(TreeNode* n) {
        if(!n)
            return 0;
        int l = sum(n->left);
        int r = sum(n->right);
        return l>r?l-r:r-l;
    }
    int findTilt(TreeNode* root) {
        int r = aNodeTilt(root);
        if(root){
            r += findTilt(root->left) + findTilt(root->right);
        }
        return r;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




