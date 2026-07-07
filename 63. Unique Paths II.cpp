#include "lib.h"
class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j] == 1) obstacleGrid[i][j] = -1;
            }
        }
        std::vector<int> memo(m,0);
        for(int i=0;i<n;i++){
            std::vector<int> curr(m, 0);
            for(int j = 0; j < m;j++){
                if(obstacleGrid[i][j] == -1){
                    curr[j] = 0;
                }else if(i == 0 && j == 0) curr[j] = 1;
                else{
                    int up,left;
                    up = left = 0;
                    if(i > 0) up = memo[j];
                    if(j > 0) left = curr[j-1];
                    curr[j] = (left + up);
                }
            }
            memo = curr;
        }
        return memo[m-1];
    }
};