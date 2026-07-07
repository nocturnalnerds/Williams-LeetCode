#include "lib.h"

class Trie {
public:
    bool isEnd;
    Trie *nextWord[26];
    Trie() {
        isEnd = false;
        for(int i=0;i<26;i++) nextWord[i] = nullptr;
    }
    
    void insert(std::string word) {
        Trie *curr = this;
        for(const auto &w : word){
            int idx = w - 'a';
            if (!curr->nextWord[idx]) curr->nextWord[idx] = new Trie();
            curr = curr->nextWord[idx];
        }
        curr->isEnd = true;
    }
    
    bool search(std::string word) {
        Trie *curr = this;
        for(const auto &w : word){
            int idx = w - 'a';
            if(!curr->nextWord[idx]) return false;
            else curr = curr->nextWord[idx];
        }
        return curr->isEnd;
    }
    
    bool startsWith(std::string prefix) {
        Trie *curr = this;
        for(const auto &w : prefix){
            int idx = w - 'a';
            if(!curr->nextWord[idx]) return false;
            else curr = curr->nextWord[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */