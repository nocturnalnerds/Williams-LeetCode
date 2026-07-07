#include "lib.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        std::stack<TreeNode*> list;
        TreeNode* node = root;

        while(!list.empty() || node != NULL){
            
            while(node != NULL){
                list.push(node);
                node = node->right;
            }

            node = list.top();
            list.pop();

            sum += node->val;
            node->val = sum;

            node = node->left;
        }
        return root;
    }
};