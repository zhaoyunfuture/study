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
		void post(Node* r,vector<int>& v) {
			if(!r)
				return;

			for(int i=0;i<r->children.size();i++) {
				post(r->children.at(i),v);
			}
			v.push_back(r->val);
		}
		vector<int> postorder(Node* root) {
			vector<int> v;
			if(!root)
				return v;
			post(root,v);
			return v;
		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




