#ifndef _TREE_HPP_
#define _TREE_HPP_

#include <string.h>
#include <string>
#include <iostream>
#include <vector>

/*! 
 *@brief node type 
 *
 */
struct node {
    int val;
    node* ln;
    node* rn;
};

/*! 
 *@brief inorder traversal (LDR)
 *
 */
void dump_LDR(node* root);

/*! 
  *@brief dump tree in human view 
  *
  */
std::string formatStr(int level, bool isFarLeft);
int heightOfTree(node* root);
void dumpTreeView(node* root,int cur,int h,bool farleft,std::vector<std::string>& tv);
void dumpTV(node* root);
/*! 
 *@brief BST (binary sort tree)
 *
 */
node* insert_bst(node* root, int v);
node* search_bst(node* root, int v);
node* delete_bst(node* root, int v);

/*!
  *@brief BST (binary search tree), also AVL tree
  *
  */
template<class T>
class TreeNode
{
    public:
        TreeNode():ln(NULL),rn(NULL),hgt(0){}
        T data;
        int hgt;
        TreeNode* ln;
        TreeNode* rn;
};

template<class T>
class AVLTree
{
    private:
        TreeNode<T>* root;
        void insertpri(TreeNode<T>* &node,T x);
        //TreeNode<T>* findpri(TreeNode<T>* node,T x);
        //void Deletepri(TreeNode<T>* &node,T x);
        int height(TreeNode<T>* node);
        void SingRotateLeft(TreeNode<T>* &k2);
        void SingRotateRight(TreeNode<T>* &k2);
        void DoubleRotateLR(TreeNode<T>* &k3);
        void DoubleRotateRL(TreeNode<T>* &k3);
        //int Max(int cmpa,int cmpb);

    public:
        AVLTree():root(NULL){}
        void insert(T x);
        //TreeNode<T>* find(T x);
        //void Delete(T x);
        void traversal();

};
#endif

