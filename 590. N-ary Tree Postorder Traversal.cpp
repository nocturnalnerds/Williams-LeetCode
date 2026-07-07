#include "lib.h"

class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    std::vector<int> arr;
    void bjir(Node *root){
        if(root == NULL){
            return;
        }
        for(auto i : root->children){
            bjir(i);
        }
        arr.push_back(root->val);
    }
    std::vector<int> postorder(Node* root) {
        bjir(root);
        return arr;
    }
    
};