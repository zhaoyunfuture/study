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
    bool isSub(TreeNode* s,TreeNode* t) {
        if(s&&t) {
            if(s->val != t->val)
                return false;
            else {
                bool l = isSub(s->left,t->left);
                bool r = isSub(s->right,t->right);
                return l&&r;
            }
        }
        else if( (!s&&t) || (s&&!t) )
            return false;
        else if( (s&&!t) || (!s&&t) )
            return false;
        else
            return true;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(isSub(s,t))
            return true;
        else {
            bool l = false;
            bool r = false;
            if(s)
                l = isSubtree(s->left,t);             
            if(s)
                r = isSubtree(s->right,t);
            return l||r;
        }
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




