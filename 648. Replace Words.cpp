#include "lib.h"
class Solution {
public:
    struct Node {
        bool isEnd; 
        Node *next[26];
        Node() {
            isEnd = false;
            for (int i = 0; i < 26; i++) next[i] = nullptr;
        }
    };
    
    Node* root = new Node();
    
    void insert(const std::string &word) {
        Node *cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!cur->next[idx]) cur->next[idx] = new Node();
            cur = cur->next[idx];
        }
        cur->isEnd = true;
    }
    
    std::string getRoot(const std::string &word) {
        Node *cur = root;
        std::string prefix;
        for (char c : word) {
            int idx = c - 'a';
            if (!cur->next[idx]) break; 
            prefix += c;
            cur = cur->next[idx];
            if (cur->isEnd) return prefix;
        }
        return word; 
    }
    
    std::string replaceWords(std::vector<std::string>& dictionary, std::string sentence) {
        
        for (const auto &w : dictionary) insert(w);
        
        std::stringstream ss(sentence);
        std::string word, result;
        
        while (ss >> word) {
            if (!result.empty()) result += " ";
            result += getRoot(word);
        }
        
        return result;
    }
};