#include "lib.h"

class Solution {
public:
    std::string resultingString( std::string s) {
        std::string ans;
        for(const char &c : s){
            if(!ans.empty()){
                char top = ans.back();
                int diff = abs(top - c);
                if(diff == 1 || diff == 25){
                    ans.pop_back();
                    continue;
                }
            }
            ans += c;
        }
        return ans;
    }
};