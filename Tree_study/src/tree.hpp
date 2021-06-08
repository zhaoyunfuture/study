#ifndef _TREE_HPP_
#define _TREE_HPP_

#include <string.h>
#include <string>
#include <iostream>

struct node {
    int val;
    node* ln;
    node* rn;
};

/*! 
 *@brief inorder traversal (LDR)
 *
 */
void dump_LDR(node* root){
    if(NULL == root)
        return;
    if(root->ln){
        dump_LDR(root->ln);
    }
    std::cout << root->val << " ";
    if(root->rn){
        dump_LDR(root->rn);
    }

}


/*! 
 *@brief BST (binary sort tree)
 *
 */

node* insert_bst(node* root,int v) {
    node* p = (node*) malloc(sizeof(node));
    p->val = v;
    p->ln = NULL;
    p->rn = NULL;

    if(NULL == root){
        root = p;
    }else if(v < root->val){
        root->ln = insert_bst(root->ln, v);
    }else{
        root->rn = insert_bst(root->rn, v);
    }

    return root;
}

node* search_bst(node* root, int v) {
    bool find = false;
    node* p = root;
    node* ret = NULL;
    while(p && !find) {
        if(v == p->val) {
            find = true;
            ret = p;
            break;
        }else if(v < p->val){
            p = p->ln;
        }else{
            p = p->rn;
        }
    }

    if(find)
        std::cout << "find" << std::endl;
    return ret;
}

node* delete_bst(node* root, int v){
    bool find = false;
    node* r = root;
    node* p = root;
    node* t = NULL;

    while(p && !find) {
        if(v == p->val) {
            find = true;
            break;
        }else if(v < p->val){
            t = p;
            p = p->ln;
        }else{
            t = p;
            p = p->rn;
        }
    }

    if(!find){
        std::cout << "not exist " << v << std::endl;
        return NULL;
    }
    
    if(p->ln == NULL && p->rn == NULL){ //the case of p is leaf node
        if(p == r){
            r = NULL;
        }else if(t->ln == p) {
            t->ln = NULL;
        }else{
            t->rn = NULL;
        }
        free(p);
    }else if(p->ln == NULL || p->rn == NULL){ // the case of p only has single branch
        if(p == r) {
            if(p->ln == NULL){
                r = p->rn;
            }else{
                r = p->ln;
            }
        }else{
            if(t->ln == p && p->ln){
                t->ln = p->ln;
            }else if(t->ln == p && p->rn) {
                t->ln = p->rn;
            }else if(t->rn == p && p->rn) {
                t->rn = p->rn;
            }else{
                t->rn = p->ln;
            }
        }
        free(p);
    }else { // the case of p has two branches
        node* pp = p;
        node* s = p->ln;
        
        while(s->rn){
            pp = s;
            s = s->rn;
        }

        p->val = s->val;
        if(pp == p){
            p->ln = NULL;
        }else{
            pp->rn = NULL;
        }
        free(s);
    }

    return r;

}

#endif

