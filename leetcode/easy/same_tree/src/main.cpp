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
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		bool isSameTree(TreeNode* p, TreeNode* q) {
			if(p == NULL && q == NULL)
			{
				return true;
			}
			else if(p != NULL && q != NULL)
			{
				if(p->val == q->val)
				{
					if(isSameTree(p->left,q->left))
					{
						if(isSameTree(p->right,q->right))
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
};

int main(int argc, char* argv[])
{
  
	return 0;
}




