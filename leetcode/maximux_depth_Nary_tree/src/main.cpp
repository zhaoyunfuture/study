#include <string.h>
#include <string>
#include <iostream>
using namespace std;

/*
*// Definition for a Node.
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
*/
class Solution {
public:
    int maxDepth(Node* root) {

        int max = 0;
        vector<Node*>::iterator it;
        if(root == NULL)
            return 0;
        if(root->children.size()==0)
            return 1;
        for(it=root->children.begin();it!=root->children.end();++it){        
            int c_max = maxDepth(*it);
            if(max<c_max)
                max = c_max;
        }
        return max+1;

#if 0
        if (root == NULL)
            return 0;

        int maxChildDepth = 0;
        for (Node* child : root->children)
        {
            int childDepth = maxDepth(child);
            if (childDepth > maxChildDepth)
                maxChildDepth = childDepth;
        }
        return 1 + maxChildDepth;   
        #endif

    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




