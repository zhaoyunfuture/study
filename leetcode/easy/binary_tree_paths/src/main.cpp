#include <string.h>
#include <string>
#include <iostream>
using namespace std;

/**
 Definition for a binary tree node.
 struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
*/
class Solution {
public:
    void btp(TreeNode* root,string s,vector<string>& v) {
        if(root->left == NULL && root->right == NULL) {
            s.append("->");
            s.append(to_string(root->val));
            v.push_back(s);
            return;
        }
        string a =s;
        if(root->left) {
            a.append("->");
            a.append(to_string(root->val));
            btp(root->left,a,v);
        }
        if(root->right) {
            s.append("->");
            s.append(to_string(root->val));
            btp(root->right,s,v);
        }

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        if(root == NULL)
            return v;
        else {
            string s = to_string(root->val);
            if (root->left == NULL && root->right == NULL) {
                v.push_back(s);
            }
            if (root->left)
                btp(root->left,s,v);
            if (root->right)
                btp(root->right,s,v);
        }
        return v;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




