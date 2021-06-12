#include <string.h>
#include <string>
#include <iostream>

#include "tree.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    node* root = NULL;
    root = (node*) malloc(sizeof(node));
    root->val = 4;
    root->ln = NULL;
    root->rn = NULL;
    for(int i=0;i<8;i++){
        if(i != 4)
            root = insert_bst(root,i);
    }
    
    dump_LDR(root);
    cout << endl;
    cout << "heightOfTree " << heightOfTree(root) << endl;
    node* p = search_bst(root,5);
    cout << p << endl;
    node* q = delete_bst(root,4);
	dump_LDR(q);
    cout << endl;
    cout << "heightOfTree " << heightOfTree(q) << endl;
    
    dumpTV(q); 
    
    AVLTree<int> avl;
    for(int i=10; i>0; i--)
        avl.insert(i);
    avl.traversal();
    avl.dumpTV();
    cout << avl.find(3) << endl;

    avl.Delete(3);
    avl.dumpTV();
    return 0;
}




