#include "lib.h"

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[15][100000];
        for (int j = 0; j <= amount; ++j) {
            if (j % coins[0] == 0) {
                dp[0][j] = j / coins[0];
            } else {
                dp[0][j] = INT_MAX;
            }
        }
        // amount = m
        // nilai target = n
        // O(n*m) -> kamu melakukan looping sebanyak n kali untuk m koin
        // Space Complexity -> O(N*M)
        // for(int i=0;i<=amount;i++){
        //     dp[0][i] = i/coins[0];
        //     cout << dp[0][i] << " ";
        // }
        for (int j = 0; j <= amount; ++j) {
            if (j % coins[0] == 0) {
                dp[0][j] = j / coins[0];
            } else {
                dp[0][j] = INT_MAX - 1;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                if(coins[i] > j){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = std::min(dp[i-1][j], dp[i][j-coins[i]] + 1);
                }
            }
        }
        return (dp[n-1][amount] == INT_MAX - 1 || dp[n-1][amount] == INT_MAX - 1) ? -1 : dp[n-1][amount];
    }
};