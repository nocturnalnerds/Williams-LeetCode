#include "lib.h"
struct Node{
    bool isEnd;
    Node *next[26];

    Node(){
        isEnd = false;
        for (int i = 0; i < 26; i++) next[i] = nullptr;
    }
};

class WordDictionary {
private:
    Node *root;

    bool allPath(std::string word, int index, Node *root){
        Node *copy = root;
        for(int j=index; j<word.length();j++){
            if(word[j] == '.'){
                for(int i=0;i<26;i++){
                    if(copy->next[i] && allPath(word,j+1,copy->next[i])){
                        return true;
                    }
                }
                return false;
            }else{
                if(!copy->next[word[j] - 'a']) return false;
                copy = copy->next[word[j] - 'a'];
            }
        }
        return copy->isEnd;
    }
public:
    WordDictionary() {
        root = new Node;
    }
    
    void addWord(std::string word) {
        Node *copy = root;
        for(int i=0;i<word.length();i++){
            if(!copy->next[word[i] - 'a']){
                copy->next[word[i] - 'a'] = new Node();
            }
            copy = copy->next[word[i] - 'a'];
        }
        copy->isEnd = true;
    }
    
    bool search(std::string word) {
        return allPath(word,0,root);
    }
};


/*

..a
a.a
a..
..

*/