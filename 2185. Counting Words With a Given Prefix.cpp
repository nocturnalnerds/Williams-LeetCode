#include "lib.h"

class Solution {
public:
    int prefixCount(std::vector<std::string>& words, std::string pref) {
        int count = 0;
        for(const std::string &s : words){
            bool flag = true;
            for(int i=0;i<pref.length();i++) {
                if(s[i] != pref[i]){
                    flag = false;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};