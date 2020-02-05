#include <string.h>
#include <string>
#include <iostream>
using namespace std;

/**
 *  * Definition for a binary tree node.
 *  */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isleaf(TreeNode* root) {
        if((root != NULL)&&(root->left == NULL)&&(root->right == NULL))
            return true;
        else
            return false;
    }
    int findleaf(TreeNode* root, int i) {
        if(isleaf(root))
            return i;
        else if(root == NULL)
            return 0;
        else
        {
            int l = findleaf(root->left,i+1);
            int r = findleaf(root->right,i+1);
            if((l==0)||(r==0))
                return (l<r) ? r:l;
            else
                return (l>r) ? r:l;
        }
    }
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        else
        {
            return findleaf(root,1);
        }
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




