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
    void tostr(TreeNode* t,string& s) {
        if(t==NULL)
            return;
        s.append(to_string(t->val));
        if(t->left==NULL && t->right==NULL)
            return;
        else if(t->left==NULL && t->right!=NULL) {
            s.append("(");
            s.append(")");
            s.append("(");
            tostr(t->right,s);
            s.append(")");
        }
        else if(t->left!=NULL && t->right==NULL) {
            s.append("(");
            tostr(t->left,s);
            s.append(")");
        }else {
            s.append("(");
            tostr(t->left,s);
            s.append(")");
            s.append("(");
            tostr(t->right,s);
            s.append(")");
        }

    }
    string tree2str(TreeNode* t) {
        string s;
        if(t==NULL)
            return s;
        tostr(t,s);
        return s;

    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




