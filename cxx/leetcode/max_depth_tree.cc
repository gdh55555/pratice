#include <iostream>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef TreeNode TreeNode;

class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if(NULL == root)
                return 0;
            else{
                int ldepth = maxDepth(root->left);
                int rdepth = maxDepth(root->right);
                return (ldepth > rdepth) ? (ldepth + 1) : (rdepth + 1);
            }
        }


};
