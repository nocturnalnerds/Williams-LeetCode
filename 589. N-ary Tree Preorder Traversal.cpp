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
    std::vector<int> preorder(Node* root) {
        std::vector<int> res;
        Node *head = root;
        if(head == NULL) return {};
        res.push_back(head->val);
        for(int i=0;i<head->children.size();i++){
            std::vector<int> temp = preorder(head->children[i]);
            res.insert(res.end(), temp.begin(), temp.end());
        }
        return res;
    }
};