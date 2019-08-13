#include <string.h>
#include <string>
#include <iostream>
using namespace std;

/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
public:
    struct mapcomp {
        bool operator() (const int& lhs, const int& rhs) const
        {return lhs<rhs;}
    };
    void loadInMap(TreeNode* t,map<int,vector<int>,mapcomp>& m, int deep) {
        if(t==NULL)
            return;
        map<int,vector<int>,mapcomp>::iterator mit;
        mit = m.find(deep);
        if(mit == m.end()){
            vector<int> v;
            v.push_back(t->val);
            m.insert(pair<int,vector<int>>(deep,v));
        }else
            mit->second.push_back(t->val);

        loadInMap(t->left,m,deep+1);
        loadInMap(t->right,m,deep+1);        
    }
    vector<double> averageOfLevels(TreeNode* root) {
        map<int,vector<int>,mapcomp> m;
        map<int,vector<int>,mapcomp>::iterator mit;
        vector<double> r;
        if(root==NULL)
            return r;
        loadInMap(root,m,0);
        for(mit=m.begin();mit!=m.end();mit++) {
            double average = 0;
            double sum = 0;
            int size = mit->second.size();
            for(int i=0;i<size;++i){
                sum +=mit->second.at(i);
            }
            average = sum/size;
            r.push_back(average);
        }

        return r;
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




