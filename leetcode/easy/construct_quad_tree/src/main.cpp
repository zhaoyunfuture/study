#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Node {
	public:
		bool val;
		bool isLeaf;
		Node* topLeft;
		Node* topRight;
		Node* bottomLeft;
		Node* bottomRight;

		Node() {}

		Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
			val = _val;
			isLeaf = _isLeaf;
			topLeft = _topLeft;
			topRight = _topRight;
			bottomLeft = _bottomLeft;
			bottomRight = _bottomRight;
		}
};
class Solution {
	public:
		bool isleaf(vector<vector<int>>& grid,int ha,int hb,int va,int vb){
			bool isl = true;
			for(int i=va;i<=vb;++i) {
				for(int j=ha;j<=hb;++j) {
					if(grid.at(va).at(ha)!=grid.at(i).at(j)){
						isl = false;
						break;
					}
				}
				if(isl == false)
					break;
			}        
			return isl;
		}
		void build(Node* root,vector<vector<int>>& grid,int ha,int hb,int va,int vb) {       
			root->val = true;
			root->isLeaf = false;
			if(isleaf(grid,ha,hb,va,vb)){
				root->val = grid.at(va).at(ha);
				root->isLeaf = true;
				root->topLeft = NULL; 
				root->topRight = NULL; 
				root->bottomLeft = NULL; 
				root->bottomRight = NULL;
				return;
			}
			if(hb-ha ==1){
				root->topLeft = new Node(grid.at(va).at(ha),true,NULL,NULL,NULL,NULL); 
				root->topRight = new Node(grid.at(va).at(hb),true,NULL,NULL,NULL,NULL); 
				root->bottomLeft = new Node(grid.at(vb).at(ha),true,NULL,NULL,NULL,NULL); 
				root->bottomRight = new Node(grid.at(vb).at(hb),true,NULL,NULL,NULL,NULL); 
				return;
			}
			if(isleaf(grid,ha,ha+(hb-ha)/2,va,va+(vb-va)/2)){
				root->topLeft = new Node(grid.at(va).at(ha),true,NULL,NULL,NULL,NULL);        
			}else {
				root->topLeft = new Node(grid.at(va).at(ha),false,NULL,NULL,NULL,NULL);
				build(root->topLeft,grid,ha,ha+(hb-ha)/2,va,va+(vb-va)/2);
				root->isLeaf = false;
			}

			if(isleaf(grid,hb-(hb-ha)/2,hb,va,va+(vb-va)/2)){
				root->topRight = new Node(grid.at(va).at(hb-(hb-ha)/2),true,NULL,NULL,NULL,NULL);     
			}else{
				root->topRight = new Node(grid.at(va).at(hb-(hb-ha)/2),false,NULL,NULL,NULL,NULL);
				build(root->topRight,grid,hb-(hb-ha)/2,hb,va,va+(vb-va)/2);
				root->isLeaf = false;
			}

			if(isleaf(grid,ha,ha+(hb-ha)/2,vb-(vb-va)/2,vb)){
				root->bottomLeft = new Node(grid.at(vb-(vb-va)/2).at(ha),true,NULL,NULL,NULL,NULL);
			}else{
				root->bottomLeft = new Node(grid.at(vb-(vb-va)/2).at(ha),false,NULL,NULL,NULL,NULL);
				build(root->bottomLeft,grid,ha,ha+(hb-ha)/2,vb-(vb-va)/2,vb);
				root->isLeaf = false;
			}

			if(isleaf(grid,hb-(hb-ha)/2,hb,vb-(vb-va)/2,vb)){
				root->bottomRight = new Node(grid.at(vb-(vb-va)/2).at(hb-(hb-ha)/2),true,NULL,NULL,NULL,NULL);
			}else{
				root->bottomRight = new Node(grid.at(vb).at(hb),false,NULL,NULL,NULL,NULL);
				build(root->bottomRight,grid,hb-(hb-ha)/2,hb,vb-(vb-va)/2,vb);
				root->isLeaf = false;
			}       

		}
		Node* construct(vector<vector<int>>& grid) {
			if(grid.size()==0)
				return NULL;
			Node* root = new Node();
			build(root,grid,0,grid.size()-1,0,grid.size()-1);
			return root;
		}
};


int main(int argc, char* argv[])
{
	Solution s;
	vector<vector<int>> v;
/*
	vector<int> v1={1,1,1,1,0,0,0,0};
	vector<int> v2={1,1,1,1,0,0,0,0};
	vector<int> v3={1,1,1,1,1,1,1,1};
	vector<int> v4={1,1,1,1,1,1,1,1};
	vector<int> v5={1,1,1,1,0,0,0,0};
	vector<int> v6={1,1,1,1,0,0,0,0};
	vector<int> v7={1,1,1,1,0,0,0,0};
	vector<int> v8={1,1,1,1,0,0,0,0};
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);
	v.push_back(v6);
	v.push_back(v7);
	v.push_back(v8);
*/
	vector<int> v1={1,1,1,1};
	vector<int> v2={1,1,1,1};
	vector<int> v3={1,1,1,1};
	vector<int> v4={1,1,1,1};
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	Node* n;
	n =s.construct(v);
	cout << n->isLeaf << endl;
	cout << n->val << endl;
	cout << n->topLeft->isLeaf << endl;
	cout << n->topLeft->val << endl;
	cout << n->topRight->isLeaf << endl;
	cout << n->topRight->val << endl;
	cout << n->bottomLeft->isLeaf << endl;
	cout << n->bottomLeft->val << endl;
	cout << n->bottomRight->isLeaf << endl;
	cout << n->bottomRight->val << endl;
	return 0;
}




