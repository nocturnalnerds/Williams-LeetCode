#include "lib.h"
class Solution {
public:
    int numOfStrings(std::vector<std::string>& patterns, std::string word) {
        int count = 0;
        for(const auto &i : patterns){
            size_t found = word.find(i);
            if(found != std::string::npos){
                ++count;
            }
        }
        return count;
    }
};