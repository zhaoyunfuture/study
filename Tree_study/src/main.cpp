#include <string.h>
#include <string>
#include <iostream>

#include "tree.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    node* root = NULL;
    for(int i=0;i<10;i++){
        root = insert_bst(root,i);
    }
    
    dump_LDR(root);
    cout << endl;

    node* p = search_bst(root,5);
    cout << p << endl;
    node* q = delete_bst(root,5);
	dump_LDR(q);
    cout << endl;
    return 0;
}




