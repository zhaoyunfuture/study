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
    vector<vector<int>> loadtov(TreeNode* r){      
        vector<vector<int>> vv;
        if(r==NULL)
            return vv;
        if(r->left==NULL && r->right==NULL){
            vector<int> v;
            v.push_back(r->val);
            vv.push_back(v);
            return vv;
        }
        vector<vector<int>> lvv;
        vector<vector<int>> rvv;
        lvv = loadtov(r->left);
        rvv = loadtov(r->right);
        for(int i=0;i<lvv.size();i++){
            lvv.at(i).push_back(r->val);
            vv.push_back(lvv.at(i));
        } 
        for(int i=0;i<rvv.size();i++){
            rvv.at(i).push_back(r->val);
            vv.push_back(rvv.at(i));
        } 
        return vv;
    }
    int sumRootToLeaf(TreeNode* root) {
        if(root==NULL)
            return 0;
        vector<vector<int>> sv;
        sv = loadtov(root);
        int sum=0;
        for(int i=0;i<sv.size();i++){
            for(int j=0;j<sv.at(i).size();j++){
                sum += pow(2,j)*sv.at(i).at(j);
            }

        }
        return sum;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




