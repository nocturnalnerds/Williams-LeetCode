#include "lib.h"

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::string ans = "";
        std::stringstream ss(s);
        std::string token;
        std::vector<std::string> lists;
        while (std::getline(ss, token, ' ')) {
            if(!token.empty()) lists.push_back(token);
        }
        const int n = lists.size();
        int k = 0;
        // C++ 20 version
        for(const auto &i : lists | std::views::reverse){
            ans += i;
            ++k;
            ans += (k < n) ? " " : "";
        }
        return ans;
    }
};