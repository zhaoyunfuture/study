#include <string.h>
#include <string>
#include <iostream>
using namespace std;

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

class Solution {
public:
    void onelevel(vector<vector<int>>& v,int index,vector<Node*> n) {
        if(n.size()==0)
            return;
        int i = 0;
        vector<Node*> node;
        if(v.size()==index){
            vector<int> val;
            for(i=0;i<n.size();++i)
                val.push_back(n.at(i)->val);
            v.push_back(val);
        }else{
            for(i=0;i<n.size();++i)
                v.at(index).push_back(n.at(i)->val);
        }
        for(i=0;i<n.size();++i){
            if(n.at(i)->children.size()!=0){
                for(int j=0;j<n.at(i)->children.size();++j)
                    node.push_back(n.at(i)->children.at(j));
            }                
        }
        onelevel(v,index+1,node);
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        if(root==NULL)
            return v;
        vector<int> top;
        top.push_back(root->val);
        v.push_back(top);
        onelevel(v,1,root->children);
        return v;        
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




