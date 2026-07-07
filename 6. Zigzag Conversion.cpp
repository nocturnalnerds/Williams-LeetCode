#include "lib.h"

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if(numRows == 1) return s;
        int n = s.length() + 1;
        char memo[1005][1005];
        for(int i=0;i<1005;i++){
            for(int j=0;j<1005;j++){
                memo[i][j] = ' ';
            }
        }
        bool down = true;
        bool side = false;
        int x = 1, y = 0;
        memo[0][0] = s[0];
        for(int i=1;i<s.length();i++){
            if(x == numRows-1){
                down = false;
                side = true;
            }else if(x == 0){
                down = true;
                side = false;
            }
            memo[x][y] = s[i];
            if(down == true){
                x++;
            }
            if(side == true){
                x--;
                y++;
            }

        }
        std::string ans = "";
        for(int i=0;i<numRows;i++){
            for(int j=0;j<s.length();j++){
                if(memo[i][j] != ' '){
                    // std::cout << memo[i][j] << '\n';
                    ans += memo[i][j];
                }
            }
        }
        return ans;
    }
};