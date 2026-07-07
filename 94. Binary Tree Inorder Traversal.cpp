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
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        
        const auto dfs = [&](auto&& self, TreeNode* root, std::vector<int>& res) -> void {
            if (!root) return;

            self(self,root->left, res);
            res.push_back(root->val);
            self(self,root->right, res);
        };
        
        dfs(dfs,root, res);

        return res;
    }
};