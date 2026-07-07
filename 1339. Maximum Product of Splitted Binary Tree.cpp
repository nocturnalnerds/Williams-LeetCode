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
    static constexpr long long MOD = 1e9 + 7;
    long long total_sum = 0;
    long long ans = 0;

    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subtree_sum = left + right + root->val;

        long long product = subtree_sum * (total_sum - subtree_sum);
        ans = std::max(ans, product);

        return subtree_sum;
    }

    int maxProduct(TreeNode* root) {
        total_sum = dfs(root);
        dfs(root);
        return ans % MOD;
    }
};