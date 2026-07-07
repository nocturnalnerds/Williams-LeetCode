#include "lib.h"

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::sort(s.begin(),s.end());
        std::sort(t.begin(),t.end());
        if(s.length() != t.length()) return false;
        for(int i=0;i<s.length();i++) if(s[i] != t[i]) return false;
        return true;
    }
};