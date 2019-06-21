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
			{return lhs>rhs;}
		};
		bool storeinset(TreeNode* r,set<int,comp>& s) {
			bool le;
			bool ri;
			if(r==NULL)
				return false;    

			if(s.find(r->val)!=s.end())
				return true;
			else {
				s.insert(r->val);
				le = storeinset(r->left,s);
				ri = storeinset(r->right,s);
				return le||ri;
			}
		}
		int getMinimumDifference(TreeNode* root) {
			set<int,comp> s;
			set<int,comp>::iterator sit1,sit2,sit3;
			int min;
			int size;
			if(storeinset(root,s))
				return 0;
			else {
				size = s.size();
				//cout << size << endl; // see how many values in set 
				sit1 = s.begin();
				sit3 = s.begin();
				sit3++;
				sit2 = sit3;
				min = *sit1-*sit2;
				//cout << min << " fisrt ";
				for(;sit2!=s.end();++sit1,++sit2) {
					if(min>(*sit1-*sit2))
						min = *sit1-*sit2;
					//cout << min << " in for ";
				}
				return min;
			}
		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




