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
    int depth(TreeNode* root){
        if(root == NULL)
            return 0;
        else
        {
            int l = depth(root->left);
            int r = depth(root->right);
            int max = (l > r) ? l:r;
            return max+1;
        }
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        else
        {
            int l = depth(root->left);
            int r = depth(root->right);
            int max = (l > r) ? l:r;
            return max+1;
        }
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




