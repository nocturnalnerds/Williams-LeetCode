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
    std::vector<double> averageOfLevels(TreeNode* root) {
        std::queue<TreeNode *> q;
        q.push(root);
        std::vector<double> ans;

        while(!q.empty()){
            int n = q.size();
            double sum = 0;
            for(int i=0;i<n;i++){
                TreeNode *front = q.front();
                q.pop();
                sum += front->val;
                if(front->left != NULL) q.push(front->left);
                if(front->right != NULL) q.push(front->right);
            }
            ans.push_back(sum / n);
        }
        return ans;
    }
};