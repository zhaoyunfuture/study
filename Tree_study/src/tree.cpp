#include "tree.hpp"

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
  *@brief dump tree in human view 
  *
  */
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

int heightOfTree(node* root){
    int l,r;
    if(!root)
        return 0;
    l = heightOfTree(root->ln) + 1;
    r = heightOfTree(root->rn) + 1;
    
    return l>r?l:r;
}

void dumpTreeView(node* root,int cur,int h,bool farleft,std::vector<std::string>& tv){
    if(0 == h)
        return;
    int c = cur;
    std::string str;
    str = formatStr(h-cur, farleft);
    if(root){
        str.append(std::to_string(root->val));
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

void dumpTV(node* root){
    //init tv
    std::vector<std::string> tv;
    std::string s;
    for(int i=0; i<=heightOfTree(root); i++){
        tv.push_back(s);
    }

    dumpTreeView(root, 0, heightOfTree(root), true, tv);

    for(int i=0; i<=heightOfTree(root); i++)
        std::cout << tv.at(i) << std::endl;

    return;
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

