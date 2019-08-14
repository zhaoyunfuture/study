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
    struct comp {
        bool operator() (const int& lhs, const int& rhs) const
        {return lhs<rhs;}
    };
    bool findInSet(TreeNode* t, int k, set<int,comp>& s) {
        if(t==NULL)
            return false;
        set<int,comp>::iterator sit;

        if(findInSet(t->left,k,s))
            return true;

        sit = s.find(t->val);
        if(sit != s.end())
            return true;

        s.insert(k-t->val);

        if(findInSet(t->right,k,s))
            return true;
        else
            return false;        
    }
    bool findTarget(TreeNode* root, int k) {
        set<int,comp> s;
        return findInSet(root,k,s);
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




