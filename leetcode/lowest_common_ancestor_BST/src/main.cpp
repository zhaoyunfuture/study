#include <string.h>
#include <string>
#include <iostream>
using namespace std;
/**
 ** Definition for a binary tree node.
 ** struct TreeNode {
 **     int val;
 **     TreeNode *left;
 **     TreeNode *right;
 **     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 ** };
 **/
class Solution {
public:
    vector<TreeNode*> fillPath(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> v;
        vector<TreeNode*> l;
        vector<TreeNode*> r;
        if(root==NULL)
            return v;
        if(root == p) {
            v.push_back(p);   
            return v;
        }
        else{
            l = fillPath(root->left,p);
            r = fillPath(root->right,p);
            if(l.size() != 0) {
                l.push_back(root->left);
                return l;
            }
            if(r.size() != 0) {
                r.push_back(root->right);
                return r;
            }            
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_path;
        vector<TreeNode*> q_path;
        vector<TreeNode*>::reverse_iterator ritp;
        vector<TreeNode*>::reverse_iterator ritq;
        TreeNode* key=NULL;
        p_path = fillPath(root,p);
        q_path = fillPath(root,q);
        ritp = p_path.rbegin();
        ritq = q_path.rbegin();
        for(;ritp!=p_path.rend();ritp++,ritq++) {
            if(*ritp == *ritq)
                key = *ritp;
            else
                break;
        }
        return key;

    }
};
int main(int argc, char* argv[])
{
  
	return 0;
}




