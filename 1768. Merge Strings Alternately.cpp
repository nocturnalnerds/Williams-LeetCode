#include "lib.h"

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        int j = 0;
        std::string output = "";
        while(j < word1.length() || j < word2.length()){
            if(j < word1.length()) output += word1[j];
            if(j < word2.length()) output += word2[j];
            j++;
        }
        return output;
    }
};