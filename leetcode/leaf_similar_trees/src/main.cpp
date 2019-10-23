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
    void storeLeaf(TreeNode* r, vector<int>& v){
        if(r==NULL)
            return;
        storeLeaf(r->left,v);
        storeLeaf(r->right,v);
        if(r->left == NULL && r->right == NULL){
            v.push_back(r->val);
            return;
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        storeLeaf(root1,v1);
        storeLeaf(root2,v2);
        int len1=v1.size();
        int len2=v2.size();
        cout << len1 << len2 ;
        if(len1!=len2)
            return false;
        else{
            for(int i=0;i<len1;i++){
                if(v1.at(i)!=v2.at(i))
                    return false;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




