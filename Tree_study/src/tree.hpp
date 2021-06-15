#ifndef _TREE_HPP_
#define _TREE_HPP_

#include <string.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
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
        void printTree(TreeNode<T>* tree , bool firstNode ) const {
            if ( tree== NULL )
                return;

            bool static outTag[64] = {false};    
            uint8_t static layer = 0;
            uint8_t i;
            ++layer;

            if ( layer >= 2 )
            {
                for (i=2; i<layer; ++i )
                    if ( outTag[i] )
                        cout << "|       ";
                    else
                        cout << "        ";
                cout << "+-------" << flush;
            }
            cout << tree->data << endl;
#if 0
            for ( i=2-1; i>0; --i)        
            {
                if ( (tree->ln+i) != NULL )    
                {                                    
                    outTag[layer] = !firstNode;
                    printTree(tree->rn, false);
                }
            }
#endif
            if ( (tree->rn) != NULL )    
            {                                    
                outTag[layer] = !firstNode;
                printTree(tree->rn, false);
            }
            if ( tree->ln != NULL )           
            {
                printTree(tree->ln, true);
                outTag[layer] = firstNode;
            }

            --layer;
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
        void printTree() const {
            printTree(root,true);
        }
};


/*! 
  *@brief RED BLACK TREE 
  *
  */
#define BLACK 1
#define RED 0

class bst {
private:

    struct Node {
        int value;
        bool color;
        Node *leftTree, *rightTree, *parent;

        Node() {
            color = RED;
            leftTree = NULL;
            rightTree = NULL;
            parent = NULL;
            value = 0;
        }

        Node* grandparent() {
            if (parent == NULL) {
                return NULL;
            }
            return parent->parent;
        }

        Node* uncle() {
            if (grandparent() == NULL) {
                return NULL;
            }
            if (parent == grandparent()->rightTree)
                return grandparent()->leftTree;
            else
                return grandparent()->rightTree;
        }

        Node* sibling() {
            if (parent->leftTree == this)
                return parent->rightTree;
            else
                return parent->leftTree;
        }
    };

    void rotate_right(Node *p) {
        Node *gp = p->grandparent();
        Node *fa = p->parent;
        Node *y = p->rightTree;

        fa->leftTree = y;

        if (y != NIL)
            y->parent = fa;
        p->rightTree = fa;
        fa->parent = p;

        if (root == fa)
            root = p;
        p->parent = gp;

        if (gp != NULL) {
            if (gp->leftTree == fa)
                gp->leftTree = p;
            else
                gp->rightTree = p;
        }

    }

    void rotate_left(Node *p) {
        if (p->parent == NULL) {
            root = p;
            return;
        }
        Node *gp = p->grandparent();
        Node *fa = p->parent;
        Node *y = p->leftTree;

        fa->rightTree = y;

        if (y != NIL)
            y->parent = fa;
        p->leftTree = fa;
        fa->parent = p;

        if (root == fa)
            root = p;
        p->parent = gp;

        if (gp != NULL) {
            if (gp->leftTree == fa)
                gp->leftTree = p;
            else
                gp->rightTree = p;
        }
    }

    void inorder(Node *p) {
        if (p == NIL)
            return;

        if (p->leftTree)
            inorder(p->leftTree);

        cout << p->value << " ";
                
        if (p->rightTree)
            inorder(p->rightTree);
    }

    string outputColor(bool color) {
        return color ? "BLACK" : "RED";
    }

    Node* getSmallestChild(Node *p) {
        if (p->leftTree == NIL)
            return p;
        return getSmallestChild(p->leftTree);
    }

    bool delete_child(Node *p, int data) {
        if (p->value > data) {
            if (p->leftTree == NIL) {
                return false;
            }
            return delete_child(p->leftTree, data);
        } else if (p->value < data) {
            if (p->rightTree == NIL) {
                return false;
            }
            return delete_child(p->rightTree, data);
        } else if (p->value == data) {
            if (p->rightTree == NIL) {
                delete_one_child(p);
                return true;
            }
            Node *smallest = getSmallestChild(p->rightTree);
            swap(p->value, smallest->value);
            delete_one_child(smallest);

            return true;
        }
    }

    void delete_one_child(Node *p) {
        Node *child = p->leftTree == NIL ? p->rightTree : p->leftTree;
        if (p->parent == NULL && p->leftTree == NIL && p->rightTree == NIL) {
            p = NULL;
            root = p;
            return;
        }
        
        if (p->parent == NULL) {
            delete  p;
            child->parent = NULL;
            root = child;
            root->color = BLACK;
            return;
        }
        
        if (p->parent->leftTree == p) {
            p->parent->leftTree = child;
        } else {
            p->parent->rightTree = child;
        }
        child->parent = p->parent;

        if (p->color == BLACK) {
            if (child->color == RED) {
                child->color = BLACK;
            } else
                delete_case(child);
        }

        delete p;
    }

    void delete_case(Node *p) {
        if (p->parent == NULL) {
            p->color = BLACK;
            return;
        }
        if (p->sibling()->color == RED) {
            p->parent->color = RED;
            p->sibling()->color = BLACK;
            if (p == p->parent->leftTree)
                rotate_left(p->sibling());
            else
                rotate_right(p->sibling());
        }
        if (p->parent->color == BLACK && p->sibling()->color == BLACK
                && p->sibling()->leftTree->color == BLACK && p->sibling()->rightTree->color == BLACK) {
            p->sibling()->color = RED;
            delete_case(p->parent);
        } else if (p->parent->color == RED && p->sibling()->color == BLACK
                && p->sibling()->leftTree->color == BLACK && p->sibling()->rightTree->color == BLACK) {
            p->sibling()->color = RED;
            p->parent->color = BLACK;
        } else {
            if (p->sibling()->color == BLACK) {
                if (p == p->parent->leftTree && p->sibling()->leftTree->color == RED
                        && p->sibling()->rightTree->color == BLACK) {
                    p->sibling()->color = RED;
                    p->sibling()->leftTree->color = BLACK;
                    rotate_right(p->sibling()->leftTree);
                } else if (p == p->parent->rightTree && p->sibling()->leftTree->color == BLACK
                        && p->sibling()->rightTree->color == RED) {
                    p->sibling()->color = RED;
                    p->sibling()->rightTree->color = BLACK;
                    rotate_left(p->sibling()->rightTree);
                }
            }
            p->sibling()->color = p->parent->color;
            p->parent->color = BLACK;
            if (p == p->parent->leftTree) {
                p->sibling()->rightTree->color = BLACK;
                rotate_left(p->sibling());
            } else {
                p->sibling()->leftTree->color = BLACK;
                rotate_right(p->sibling());
            }
        }
    }

    void insert(Node *p, int data) {
        if (p->value >= data) {
            if (p->leftTree != NIL)
                insert(p->leftTree, data);
            else {
                Node *tmp = new Node();
                tmp->value = data;
                tmp->leftTree = tmp->rightTree = NIL;
                tmp->parent = p;
                p->leftTree = tmp;
                insert_case(tmp);
            }
        } else {
            if (p->rightTree != NIL)
                insert(p->rightTree, data);
            else {
                Node *tmp = new Node();
                tmp->value = data;
                tmp->leftTree = tmp->rightTree = NIL;
                tmp->parent = p;
                p->rightTree = tmp;
                insert_case(tmp);
            }
        }
    }

    void insert_case(Node *p) {
        if (p->parent == NULL) {
            root = p;
            p->color = BLACK;
            return;
        }
        if (p->parent->color == RED) {
            if (p->uncle()->color == RED) {
                p->parent->color = p->uncle()->color = BLACK;
                p->grandparent()->color = RED;
                insert_case(p->grandparent());
            } else {
                if (p->parent->rightTree == p && p->grandparent()->leftTree == p->parent) {
                    rotate_left(p);
                    rotate_right(p);
                    p->color = BLACK;
                    p->leftTree->color = p->rightTree->color = RED;
                } else if (p->parent->leftTree == p && p->grandparent()->rightTree == p->parent) {
                    rotate_right(p);
                    rotate_left(p);
                    p->color = BLACK;
                    p->leftTree->color = p->rightTree->color = RED;
                } else if (p->parent->leftTree == p && p->grandparent()->leftTree == p->parent) {
                    p->parent->color = BLACK;
                    p->grandparent()->color = RED;
                    rotate_right(p->parent);
                } else if (p->parent->rightTree == p && p->grandparent()->rightTree == p->parent) {
                    p->parent->color = BLACK;
                    p->grandparent()->color = RED;
                    rotate_left(p->parent);
                }
            }
        }
    }

    void DeleteTree(Node *p) {
        if (!p || p == NIL) {
            return;
        }
        DeleteTree(p->leftTree);
        DeleteTree(p->rightTree);
        delete p;
    }

    void printTree(Node* tree , bool firstNode ) const {
            if ( tree== NULL )
                return;

            bool static outTag[64] = {false};    
            uint8_t static layer = 0;
            uint8_t i;
            ++layer;

            if ( layer >= 2 )
            {
                for (i=2; i<layer; ++i )
                    if ( outTag[i] )
                        cout << "|       ";
                    else
                        cout << "        ";
                cout << "+-------" << flush;
            }
            cout << tree->value << (tree->color? 'B':'R') << endl;

            if ( (tree->rightTree) != NULL )    
            {                                    
                outTag[layer] = !firstNode;
                printTree(tree->rightTree, false);
            }
            if ( tree->leftTree != NULL )           
            {
                printTree(tree->leftTree, true);
                outTag[layer] = firstNode;
            }

            --layer;
        }
public:

    bst() {
        NIL = new Node();
        NIL->color = BLACK;
        root = NULL;
    }

    ~bst() {
        if (root)
            DeleteTree(root);
        delete NIL;
    }

    void inorder() {
        if (root == NULL)
            return;
        inorder(root);
        cout << endl;
    }

    void insert(int x) {
        if (root == NULL) {
            root = new Node();
            root->color = BLACK;
            root->leftTree = root->rightTree = NIL;
            root->value = x;
        } else {
            insert(root, x);
        }
    }

    bool delete_value(int data) {
        return delete_child(root, data);
    }
    void printTree() const {
        printTree(root,true);
    }
private:
    Node *root, *NIL;
};

#endif
