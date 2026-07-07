#include "lib.h"

class Solution {
public:
    int minLength(std::string s) {
        std::string new_string = s;
        while(true){
            std::string temp = "";
            bool change = false;
            int cur_length = new_string.length();
            for(int i=0;i<new_string.length();i++){
                if(((new_string[i] == 'A' && new_string[i+1] == 'B') || (new_string[i] == 'C' && new_string[i+1] == 'D')) && i < new_string.length() - 1){
                    cur_length -= 2;
                    change = true;
                    i+=1;
                }else{
                    temp += new_string[i];
                }
            }
            new_string = temp;
            // cout << new_string << endl;
            if(!change) break;
        }
        return new_string.length();
    }
};