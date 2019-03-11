#include <string.h>
#include <string>
#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	public:
		bool isSameTree(TreeNode* p,TreeNode* q){
			if(p == NULL && q == NULL)
				return true;
			else if(p != NULL && q != NULL)
			{
				if(p->val == q->val)
				{
					if(isSameTree(p->left,q->right))
					{
						if(isSameTree(p->right,q->left))
							return true;
						else
							return false;
					}
					else
						return false;
				}
				else
					return false;
			}
			else
				return false;
		}

		bool isSymmetric(TreeNode* root) {
			if (root != NULL)
				return isSameTree(root->left,root->right);
			else
				return true;
		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




