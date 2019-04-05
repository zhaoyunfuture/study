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
    vector<TreeNode*> fillPath(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> v;
        vector<TreeNode*> l;
        vector<TreeNode*> r;
        if(root==NULL)
            return v;
        //cout << "val = " << root->val << endl;
        if(root->val == p->val) {
            v.push_back(root);   
            return v;
        }
        else{
            l = fillPath(root->left,p);           
            r = fillPath(root->right,p);            
            if(l.size() != 0) {
                l.push_back(root);
                return l;
            }            
            else if(r.size() != 0){
                r.push_back(root);
                return r;
            } else return v;           
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_path;
        vector<TreeNode*> q_path;
        vector<TreeNode*>::reverse_iterator ritp;
        vector<TreeNode*>::reverse_iterator ritq;
        TreeNode* key=NULL;
        q_path = fillPath(root,q);
        p_path = fillPath(root,p);   
        cout << "q size " << q_path.size() <<endl;
        cout << "p size " << p_path.size() << endl;
        ritp = p_path.rbegin();
        ritq = q_path.rbegin();        
        int min = q_path.size() > p_path.size()?p_path.size():q_path.size();
        cout << "min" << min << endl;
        for(int i=0;i<min;++i) {
            if(*ritp == *ritq) {
                key = *ritp;               
            }
            else
                break;
            ritp++;
            ritq++;
        }
        return key;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




