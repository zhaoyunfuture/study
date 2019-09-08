#include <string.h>
#include <string>
#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	public:
		TreeNode* searchBST(TreeNode* root, int val) {
			TreeNode* n;
			if(root == NULL)
				return NULL;
			if(root->val == val)
				return root;
			if(root->left ==NULL && root->right == NULL)
				return NULL;
			n = searchBST(root->left,val);
			if(n)
				return n;
			else {
				n = searchBST(root->right,val);
				if(n)
					return n;
				else
					return NULL;
			}
		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




