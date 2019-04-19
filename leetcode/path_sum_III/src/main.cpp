#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
	public:
	//the first recursion: used to calu the pathNum from this root node to all child
		int ps(TreeNode* root,int sum, int cur){
			int l=0;
			int r=0;
			if(!root)
				return 0;
			else if((root->val + cur) == sum){
				l = ps(root->left,sum,cur+root->val);
				r = ps(root->right,sum,cur+root->val);
				return 1+l+r;
			}            
			else{
				l = ps(root->left,sum,cur+root->val);
				r = ps(root->right,sum,cur+root->val);
				return l+r;
			}
		}
	//the second recursion:used to calu all the node treated as root, to sum up 
		int aps(TreeNode* root,int sum) {
			if(!root)
				return 0;
			else if(root->left==NULL && root->right==NULL)
				return ps(root,sum,0);
			else{
				int le = aps(root->left,sum);
				int ri = aps(root->right,sum);
				int ro = ps(root,sum,0);
				return le+ri+ro;
			}

		}
		int pathSum(TreeNode* root, int sum) {
			if(!root)
				return 0;
			return aps(root,sum);
		}
};

int main(int argc, char* argv[])
{

	return 0;
}




