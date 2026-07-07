#include "lib.h"

class Solution {
public:
    std::string generateTheString(int n) {
        std::string res = "";
        bool flag = false;
        if(!(n & 1)){
            n--;
            flag = true;
        }
        for(int i=0;i<n;i++) res += "a";
        if(flag) res += "b";
        return res;
    }
};