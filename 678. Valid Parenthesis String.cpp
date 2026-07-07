#include "lib.h"

class Solution {
public:
    bool checkValidString(std::string s) {
        int minn = 0;
        int maxx = 0;
        for(auto &i : s){
            if(i == '('){
                minn++;
                maxx++;
            }else if(i == ')'){
                minn--;
                maxx--;
            }else{
                maxx++;
                minn--;
            }

            if(maxx < 0) return false;
            
            minn = std::max(minn, 0);
        }
        return minn == 0;
    }
};