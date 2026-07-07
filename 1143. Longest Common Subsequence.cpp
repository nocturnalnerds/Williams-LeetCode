#include "lib.h"

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        const int n = text1.length();
        const int m = text2.length();
        int dp[n+1][text2.length()+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};

/*
  a c e
  a b c d e
 0 1 2 3 4 5
0
1
2
3


*/