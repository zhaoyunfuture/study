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
        TreeNode():ln(NULL),rn(NULL){}
        T data;
        TreeNode* ln;
        TreeNode* rn;
};

template<class T>
class AVLTree
{
    private:
        TreeNode<T>* root;
        void insertpri(TreeNode<T>* &node, TreeNode<T>* pNode, T x){
            if(node==NULL)
            {
                node=new TreeNode<T>();
                node->data=x;
                return;
            }
            if(node->data > x)
            {
                insertpri(node->ln, node, x);
                if(2 == height(node->ln)-height(node->rn)) {
                    if(x < node->ln->data)
                        SingRotateLeft(node, pNode);
                    else
                        DoubleRotateLR(node, pNode);
                }
            }
            else if(node->data < x)
            {
                insertpri(node->rn, node, x);
                if(2 == height(node->rn)-height(node->ln)) {
                    if(x > node->rn->data)
                        SingRotateRight(node, pNode);
                    else
                        DoubleRotateRL(node, pNode);
                }
            }

        }
        TreeNode<T>* findpri(TreeNode<T>* node,T x){
            if(node==NULL)
            {
                return NULL;
            }
            if(node->data > x)
            {
                return findpri(node->ln,x);
            }
            else if(node->data < x)
            {
                return findpri(node->rn,x);
            }
            else return node;
        }

        void Deletepri(TreeNode<T>* &node, TreeNode<T>* pNode, T x){
            if(node==NULL) return ;
            if(x < node->data)
            {
                Deletepri(node->ln, node, x);
                if(2 == height(node->rn)-height(node->ln)){
                    if(node->rn->ln != NULL && (height(node->rn->ln)>height(node->rn->rn)) )
                        DoubleRotateRL(node, pNode);
                    else
                        SingRotateRight(node, pNode);
                }
            }
            else if(x > node->data)
            {
                Deletepri(node->rn, node, x);
                if(2 == height(node->ln)-height(node->rn)){
                    if(node->ln->rn != NULL && (height(node->ln->rn)>height(node->ln->ln) ))
                        DoubleRotateLR(node, pNode);
                    else
                        SingRotateLeft(node, pNode);
                }
            }
            else
            {
                if(node->ln && node->rn)
                {
                    TreeNode<T>* temp = node->rn;
                    while(temp->ln!=NULL) temp=temp->ln;
                    node->data=temp->data;
                    Deletepri(node->rn, node, temp->data);
                    if(2 == height(node->ln)-height(node->rn))
                    {
                        if(node->ln->rn!=NULL&& (height(node->ln->rn)>height(node->ln->ln) ))
                            DoubleRotateLR(node, pNode);
                        else
                            SingRotateLeft(node, pNode);
                    }
                }
                else
                {
                    TreeNode<T>* temp = node;
                    if(node->ln == NULL)
                        node = node->rn;
                    else if(node->rn == NULL)
                        node = node->ln;
                    delete(temp);
                    temp=NULL;
                }
            }
            if(node == NULL) return;
            return;
        }

        int height(TreeNode<T>* node){
            int l,r;
            if(!node)
                return 0;
            l = height(node->ln) + 1;
            r = height(node->rn) + 1;

            return l>r?l:r;
        }

        void SingRotateLeft(TreeNode<T>* &k2, TreeNode<T>* &pk2){
            TreeNode<T>* k1;
            k1=k2->ln;
            k2->ln=k1->rn;
            k1->rn=k2;
            if(root == k2){
                root = k1;
            }
            if(pk2){
                pk2->ln = k1;
            }
        }

        void SingRotateRight(TreeNode<T>* &k2, TreeNode<T>* &pk2){
            TreeNode<T>* k1;
            k1=k2->rn;
            k2->rn=k1->ln;
            k1->ln=k2;
            if(root == k2){
                root = k1;
            }
            if(pk2){
                pk2->rn = k1;
            }
        }

        void DoubleRotateLR(TreeNode<T>* &k3, TreeNode<T>* &pk3){
            SingRotateRight(k3->ln, pk3);
            SingRotateLeft(k3, pk3);
        }

        void DoubleRotateRL(TreeNode<T>* &k3, TreeNode<T>* &pk3){
            SingRotateLeft(k3->rn, pk3);
            SingRotateRight(k3, pk3);
        }
        
        std::string formatStr(int level, bool isFarLeft){
            std::string str;
            if(0 == level)
                return str;

            int cnt = 1<<(level-1);

            if(isFarLeft)
                cnt /= 2; 

            for(int i=0; i<=cnt; i++){
                str.append(" ");
            }
            return str;
        }

        void dumpTreeView(TreeNode<T>* root,int cur,int h,bool farleft,std::vector<std::string>& tv){
            if(0 == h)
                return;
            int c = cur;
            std::string str;
            str = formatStr(h-cur, farleft);
            if(root){
                str.append(std::to_string(root->data));
            }else{
                if(cur != h)
                    str.append("x");
            }
            tv.at(cur).append(str);
            if(!root){
                if(cur == h || cur+1 == h)
                    return;
                if(farleft)
                    tv.at(cur+1).append("x x");
                else
                    tv.at(cur+1).append(" x x");
                return;
            }
            dumpTreeView(root->ln, c+1, h, true&&farleft, tv);
            dumpTreeView(root->rn, c+1, h, false&&farleft, tv);
        }

    public:
        AVLTree():root(NULL){}
        void insert(T x){
            insertpri(root,NULL,x);
        }
        TreeNode<T>* find(T x){
            return findpri(root,x);
        }
        
        void Delete(T x){
            Deletepri(root, NULL, x);
        }
        void traversal() {
            dump_LDR(root);
            std::cout << std::endl;
        }
        void dump_LDR(TreeNode<T>* root){
            if(NULL == root)
                return;
            if(root->ln){
                dump_LDR(root->ln);
            }
            std::cout << root->data << " ";
            if(root->rn){
                dump_LDR(root->rn);
            }
        }
        void dumpTV(){
            //init tv
            std::vector<std::string> tv;
            std::string s;
            for(int i=0; i<=height(root); i++){
                tv.push_back(s);
            }

            dumpTreeView(root, 0, height(root), true, tv);

            for(int i=0; i<=height(root); i++)
                std::cout << tv.at(i) << std::endl;
        }
};

#endif
