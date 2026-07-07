#include "lib.h"

class Solution {
public:
    int memo[101][101];
    int uniquePaths(int m, int n) {
        memset(memo,0,sizeof(memo));
        for(int i=1;i<=m;i++) memo[i][1] = 1;
        for(int i=1;i<=n;i++) memo[1][i] = 1;
        for(int i=2;i<=m;i++){
            for(int j=2;j<=n;j++){
                memo[i][j] = memo[i-1][j] + memo[i][j-1];
            }
        }
        return memo[m][n];
    }
};
