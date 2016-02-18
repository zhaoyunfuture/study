/*
There is a binary tree, the node is ether positive integer or negative interger.
To find a subtree to make the sum of its nodes is the max.
*/

#include "tree_common.h"

int result;
bool maxSet;

void postOrderVisit(BTNode* root) {
	if( root == NULL ) {
		return;
	}
	if( root->left != NULL ) {
		postOrderVisit(root->left);
		root->node_value += root->left->node_value;
		cout << "root_v:" << root->node_value << " root_l_v:" << root->left->node_value << endl;
	}
        if( root->right != NULL ) {
                postOrderVisit(root->right);
                root->node_value += root->right->node_value;
		cout << "root_v:" << root->node_value << " root_r_v:" << root->left->node_value << endl;
        }
	if( maxSet ) {
		if(root->node_value > result)
			result = root->node_value;
	}
	else {
		result = root->node_value;
		maxSet = true;
	}
}

int main() {
        BTNode *root = NULL;
        root = CreateBTree(root);
	cout<< "print first start" << endl;
	PrintBTree(root);
	cout<< "print first finished" << endl;
	postOrderVisit(root);
        cout << endl;
	cout<< "print second finished" << endl;
        PrintBTree(root);
	cout<< "print second finished" << endl;
}
