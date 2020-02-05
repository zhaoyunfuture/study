#include <string.h>
#include <string>
#include <iostream>
using namespace std;

/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
public:   
    void inc(TreeNode* r,vector<int>& v){
        if(r==NULL)
            return;
        inc(r->left,v);         
        v.push_back(r->val);        
        inc(r->right,v);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL)
            return NULL;
        vector<int> v;
        inc(root,v);

        TreeNode* head;
        TreeNode* tmp;
        TreeNode* node = new TreeNode(v.at(0));
        head = node;
        if(v.size()>1){
            for(int i=1;i<v.size();i++){
                tmp = new TreeNode(v.at(i));
                node->right = tmp;
                node = node->right;
            }
        }
        return head;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




