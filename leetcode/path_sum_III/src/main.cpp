#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int ps(TreeNode* root,int sum, int cur){
        if(!root)
            return 0;
        else if(root->val == sum && cur==0)
            return 1;
        else if((root->val + cur) == sum)
            return 1;
        else{
            int l = ps(root->left,sum,cur+root->val);
            int r = ps(root->right,sum,cur+root->val);
            return l+r;
        }
    }
    int aps(TreeNode* root,int sum) {
        if(!root)
            return 0;
        int le = ps(root->left,sum,0);
        int ri = ps(root->right,sum,0);
        int ro = ps(root,sum,0);
        return le+ri+ro;

    }
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        int le = ps(root->left,sum,0);
        int ri = ps(root->right,sum,0);
        int ro = ps(root,sum,0);
        return le+ri+ro;
    }
};
int main(int argc, char* argv[])
{
  
	return 0;
}




