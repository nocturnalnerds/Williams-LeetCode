#include "lib.h"

class Solution {
public:
    int change(int amount, std::vector<int>& coins) {
        short n = coins.size();
        unsigned int dp[305][5005];
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(short i=1;i<=n;i++){
            for(short j=0;j<=amount;j++){
                dp[i][j] += dp[i - 1][j];
                if(j-coins[i-1] >= 0){
                    dp[i][j] += dp[i][j-coins[i-1]];
                }
            }
        }
        return dp[n][amount];
    }
};

/*
        0 1 2 3 4 5
0       0 0 0 0 0 0
1       0 1 1 1 1 1
1,2     0 1 2 2 3 3
1,2,5   0 1 2 2 3 4

1.500.000

*/