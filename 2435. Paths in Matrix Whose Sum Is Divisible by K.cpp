#include "lib.h"

const int MOD = 1e9 + 7;
class Solution {
public:
    int count = 0;
    int numberOfPaths(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<std::vector<int>>> dp(m, std::vector<std::vector<int>>(n, std::vector<int>(k,0)));

        dp[0][0][grid[0][0] % k] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 && j == 0) continue;
                for(int r = 0; r < k; r++){
                    int rem = (r + grid[i][j]) % k;
                    if(i > 0){
                        dp[i][j][rem] = (dp[i][j][rem] + dp[i-1][j][r]) % MOD;
                    }
                    if(j > 0){
                        dp[i][j][rem] = (dp[i][j][rem] + dp[i][j-1][r]) % MOD;
                    }
                }
            }
        }
        return dp[m-1][n-1][0];
    }
};