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
		struct comp {
			bool operator() (const int& lhs, const int& rhs) const
			{return lhs<rhs;}
		};
		void storeInMap(TreeNode* r,map<int,int,comp>& m) {
			map<int,int,comp>::iterator mit;
			if(r==NULL)
				return;
			mit = m.find(r->val);
			if(mit == m.end())
				m.insert(pair<int,int>(r->val,1));
			else
				mit->second++;

			storeInMap(r->left,m);
			storeInMap(r->right,m);
		}
		void greater(TreeNode* r,map<int,int,comp>& m) {
			map<int,int,comp>::iterator mit;
			if(r==NULL)
				return;
			mit = m.find(r->val);
			mit++;
			for(;mit!=m.end();++mit) {
				r->val +=mit->first * mit->second;
			}
			greater(r->left,m);
			greater(r->right,m);
		}
		TreeNode* convertBST(TreeNode* root) {
			if(root == NULL)
				return NULL;

			map<int,int,comp> m;
			storeInMap(root,m);
			greater(root,m);
			return root;        
		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




