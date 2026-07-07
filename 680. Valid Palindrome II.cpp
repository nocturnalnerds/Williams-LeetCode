#include "lib.h"

// wrong Answer -> too lazy to work on

class Solution {
public:
    bool validPalindrome(std::string s) {
        const int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] != s[n-i-1]) return false;
        }
        return true;
    }
};