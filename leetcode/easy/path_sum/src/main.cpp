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
	bool trysum(TreeNode* root, int sum, int key)
	{
		if(root == NULL)
			return false;
		else if((root->left == NULL)&&(root->right == NULL))
		{
			if((root->val + sum) == key)
				return true;
			else
				return false;
		}
		else
		{
			bool l = trysum(root->left,root->val + sum,key);
			bool r = trysum(root->right,root->val + sum,key);
			return l||r;
		}

	}
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return false;
		else
			return trysum(root,0,sum);
	}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




