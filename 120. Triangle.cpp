#include "lib.h"

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        int memo[205][205];
        for(int i=0;i<205;i++){
            for(int j=0;j<205;j++){
                memo[i][j] = 1e7;
            }
        }
        memo[0][0] = triangle[0][0];
        for(int i=1;i<triangle.size();i++){
            for(int j=0;j<=i;j++){
                if(j > 0) memo[i][j] = triangle[i][j] + std::min(memo[i-1][j], memo[i-1][j-1]);
                else memo[i][j] = triangle[i][j] + memo[i-1][j];
            }
        }
        int ans = INT_MAX;
        for(int j=0;j<triangle.size();j++){
            ans = std::min(memo[triangle.size()-1][j],ans); 
        }
        return ans;
    }
};