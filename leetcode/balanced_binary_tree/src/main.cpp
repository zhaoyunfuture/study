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
	bool isBal(TreeNode* p,TreeNode* q) {
		int l = maxDepth(p);
		int r = maxDepth(q);
		if((l-r)>1 || (l-r)<-1)
			return false;
		else if(l == 0 || r == 0)
			return true;
		else
		{
			if(isBal(p->left,p->right))
			{
				if(isBal(q->left,q->right))
					return true;
				else
					return false;
			}
			else
				return false;
		}
			return true;
	}
	bool isBalanced(TreeNode* root) {
		if(root == NULL)
			return true;
		else
		{
			return isBal(root->left,root->right);	
		}
	}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




