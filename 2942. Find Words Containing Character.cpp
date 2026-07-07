#include "lib.h"
class Solution {
public:
    std::vector<int> findWordsContaining(std::vector<std::string>& words, char x) {
        std::vector<int> exist;
        int k = 0;
        for(auto i : words){
            if(i.find(x) != std::string::npos){
                exist.push_back(k);
            }
            ++k;
        }

        return exist;
    }
};