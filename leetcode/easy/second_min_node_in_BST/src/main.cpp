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
    void storeInSet(TreeNode* r,set<int,comp>& s) {
        if(r==NULL)
            return;
        if(r->left == NULL) {
            set<int,comp>::iterator sit;
            sit = s.find(r->val);
            if(sit == s.end())
                s.insert(r->val);
            return;
        }
        else{
            set<int,comp>::iterator sit;
            sit = s.find(r->val);
            if(sit == s.end())
                s.insert(r->val);
            storeInSet(r->left,s);
            storeInSet(r->right,s);
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int,comp> s;
        set<int,comp>::iterator sit;
        if(root == NULL)
            return -1;
        storeInSet(root,s);
        if(s.size()==1)
            return -1;
        else {
            sit = s.begin();
            sit++;
            return *sit;
        }

    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




