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

		int deep(TreeNode* r,int& max) {
			int le,ri;
			if(r == NULL)
				return 0;
			le = deep(r->left,max);
			ri = deep(r->right,max);
			if((le+ri)>max)
				max = le+ri;
			return le>ri?le+1:ri+1;
		}
		int diameterOfBinaryTree(TreeNode* root) {
			if(root==NULL)
				return 0;
			int max = 0;
			deep(root,max);
			return max;
		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




