#include "lib.h"

class Solution {
public:
    char findTheDifference(std::string s, std::string t) {
        s += t;
        int c = 0;
        for(const auto &x: s){
            c ^= x;
        }
        return c;
    }
};