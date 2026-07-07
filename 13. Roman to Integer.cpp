#include "lib.h"

int rettoROM(char c){
    if(c == 'I') return 1;
    else if(c == 'V') return 5;
    else if(c == 'X') return 10;
    else if(c == 'L') return 50;
    else if(c == 'C') return 100;
    else if(c == 'D') return 500;
    else if(c == 'M') return 1000;
    return -1;
}
    
class Solution {
public:
    
    int romanToInt(std::string s) {
        int count = 0;
        for(int i=0;i<s.length();i++){
            if(rettoROM(s[i]) < rettoROM(s[i+1])){
                count -= rettoROM(s[i]);
            }else{
                count += rettoROM(s[i]);
            }
        }
        return count;
    }
};