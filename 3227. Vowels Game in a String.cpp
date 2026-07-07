#include "lib.h"
class Solution {
public:
    bool doesAliceWin(std::string s) {
        for(int i=0;i<s.length();i++){
            if(s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o') return true;
        }
        return false;
    }
};

/*

A : leetcode
B : r
*/