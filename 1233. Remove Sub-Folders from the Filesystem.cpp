#include "lib.h"
struct Node{
    std::unordered_map<std::string, Node*> child;
    bool isEnd;
    Node(){
        isEnd = false;
    }
};

class Trie{
    private:
        Node *root;
    public:
        Trie(){
            root = new Node();
        }
        
        void insert(std::vector<std::string> word){
            Node *start = root;
            for(const auto &i : word){
                if(start->child[i] == NULL){
                    start->child[i] = new Node();
                }
                start = start->child[i];
            }
            start->isEnd = true;
        }
        bool traverse(std::vector<std::string> word){
            Node *start = root;
            int k = 1;
            for(const auto &i : word){
                if(start->child[i] == nullptr) return false;
                if(start->isEnd) return false;
                start = start->child[i];
                k++;
            }
            return start->isEnd;
        }
};

class Solution {
    private:
        std::vector<std::string> processString(std::string word){
            std::vector<std::string> parsed;
            std::string copy;
            for(int i=0;i<word.length();i++){
                if(i==0) continue;
                if(word[i] == '/') {
                    parsed.push_back(copy);
                    copy = "";
                    continue;
                }
                else{
                    copy += word[i];
                }
            }
            parsed.push_back(copy);
            return parsed;
        }
    public:
        std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
            std::vector<std::vector<std::string>> processed;
            Trie trie;
            for(const std::string &x : folder){
                // cout << x << ": ";
                std::vector<std::string> temp = processString(x);
                // for(auto i : temp){
                //     cout << i << endl;
                // }
                processed.push_back(temp);
                trie.insert(temp);
            }

            // for(const auto &x : processed){
            //     for(auto i : x){
            //         cout << i << " ";
            //     }
            //     cout << endl;
            // }

            std::vector<std::string> res;

            for(int i=0;i<processed.size();i++){
                if(trie.traverse(processed[i])){
                    // cout << trie.traverse(processed[i]) << endl;
                    res.push_back(folder[i]);
                }
            }
            // cout << trie.traverse({"ab"});
            return res;
        }
};
