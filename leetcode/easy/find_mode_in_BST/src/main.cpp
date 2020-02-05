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
		void store(TreeNode* node, vector<int>& v) {
			if(node==NULL)
				return;
			v.push_back(node->val);
			store(node->left,v);
			store(node->right,v);
			return;
		}
		vector<int> findMode(TreeNode* root) {
			vector<int> v;
			vector<int> r;
			if(root==NULL)
				return v;
			store(root,v);

			if(v.size()==1)
				return v;
			map<int,int> m;
			map<int,int>::iterator mit;
			int max = 0;
			for(int i=0;i<v.size();++i) {

				mit = m.find(v.at(i));
				if(mit == m.end()) {
					m.insert(pair<int,int>(v.at(i),1));

					if(1>max) {
						r.push_back(v.at(i));
						max = 1;
					}else if(max ==1)
						r.push_back(v.at(i));
				}
				else {
					mit->second ++;

					if(mit->second > max) {
						r.clear();
						r.push_back(mit->first);
						max = mit->second;
					}else if(mit->second == max) {
						r.push_back(mit->first);
						max = mit->second;
					}                   
				}
			}
			return r;
		}
};
int main(int argc, char* argv[])
{
  
	return 0;
}




