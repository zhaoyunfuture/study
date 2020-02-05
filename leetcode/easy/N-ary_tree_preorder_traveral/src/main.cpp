#include <string.h>
#include <string>
#include <iostream>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
int val;
vector<Node*> children;

Node() {}

Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};
 */
class Solution {
	public:
		void pre(Node* r,vector<int>& v) {
			if(!r)
				return;
			v.push_back(r->val);
			for(int i=0;i<r->children.size();i++) {
				pre(r->children.at(i),v);
			}
		}
		vector<int> preorder(Node* root) {
			vector<int> v;
			if(!root)
				return v;
			pre(root,v);
			return v;

		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




