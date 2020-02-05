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
    bool level(TreeNode* pCur,TreeNode* root,int x,int& lx,int lev,TreeNode** pExp) {
        if(root==NULL)
            return false;
        if(root->val == x){
            lx = lev;
            *pExp = pCur;
            return true;
        }
        lev++;
        if(level(root,root->left,x,lx,lev,pExp))
            return true;
        return level(root,root->right,x,lx,lev,pExp);


    }
    bool isCousins(TreeNode* root, int x, int y) {
        int lx=0;
        int ly=0;
        int lev=0;
        TreeNode* p1;
        TreeNode* p2;
        if(level(NULL,root,x,lx,lev,&p1));          
        lev =0;
        if(level(NULL,root,y,ly,lev,&p2));

        if(p1==NULL || p2==NULL)
            return false;

        if(lx!=ly)
            return false;
        else{
            if(p1->val == p2->val)
                return false;
            else
                return true;
        }
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




