#include "lib.h"

class Solution {
public:
    int getLucky(std::string s, int k) {
        std::string convert = "";
        for(int i=0;i<s.length();i++){
            int dig = (s[i] - 'a') + 1;
            std::string temp = std::to_string(dig);
            convert += temp;
        }
        std::cout << convert << '\n';
        while(k--){
            int dig = 0;
            for(const char &c : convert){
                dig += (c - '0');
            }
            convert = std::to_string(dig);
        }
        return std::stoi(convert);
    }
};