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
		bool isleaf(TreeNode* root) {
			if((root != NULL)&&(root->left == NULL)&&(root->right == NULL))
				return true;
			else
				return false;
		}
		int findleaf(TreeNode* root,bool left) {
			if(isleaf(root)&&left) {
				return root->val;
			}            
			else if(root == NULL)
				return 0;
			else
			{
				int l = findleaf(root->left,1);
				int r = findleaf(root->right,0);

				return l+r;            
			}
		}

		int sumOfLeftLeaves(TreeNode* root) {
			if(root==NULL)
				return 0;
			else
				return findleaf(root->left,1)+findleaf(root->right,0);
		}
};
int main(int argc, char* argv[])
{
  
	return 0;
}




