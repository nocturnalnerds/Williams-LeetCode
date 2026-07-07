#include "lib.h"

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = s.length();
        int maxLength = 0;
        int charIndex[128];
        memset(charIndex,-1,sizeof(charIndex));
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (charIndex[s[right]] >= left) {
                left = charIndex[s[right]] + 1;
            }
            charIndex[s[right]] = right;
            maxLength = std::max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};