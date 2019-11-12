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
    void sum(TreeNode* r,int L,int R,int& s){
        if(r==NULL)
            return;
        if(r->val >=L && r->val <= R)
            s += r->val;
        sum(r->left,L,R,s);
        sum(r->right,L,R,s);
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root==NULL)
            return 0;
        int s=0;
        sum(root,L,R,s);
        return s;
    }
};
int main(int argc, char* argv[])
{
  
	return 0;
}




