#include <string.h>
#include <string>
#include <iostream>
#include <vector>
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
    void fill(TreeNode* root,int depth,int i,vector<vector<int>>& v) {
        if(root == NULL)
            return;
        else
        {
            v.at(depth-i).push_back(root->val);
            fill(root->left,depth,i+1,v);
            fill(root->right,depth,i+1,v);
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> r;
        if(root == NULL)
            return r;
        else
        {
            int depth = maxDepth(root);
            vector<vector<int>> res(depth);
            fill(root,depth-1,0,res);
            return res;
        }
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




