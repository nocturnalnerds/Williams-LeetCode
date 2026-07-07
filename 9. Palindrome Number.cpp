#include "lib.h"
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        std::string temp = "";
        while(x != 0){
            temp += x % 10;
            x = x / 10;
        }
        for(int i=0;i<temp.length();i++){
            if(temp[i] != temp[temp.length() - i - 1]) return false;
        }
        return true;
    }
};