#include "lib.h"

class Solution {
public:
    int countSubmatrices(std::vector<std::vector<int>>& grid, int k) {
        const int n = grid.size();
        const int m = grid[0].size();

        std::vector<std::vector<int>> fill(n,std::vector<int>(m));
        fill[0][0] = grid[0][0];
        for(int i=1;i<m;i++){
            fill[0][i] = grid[0][i] + fill[0][i-1];
        }
        for(int i=1;i<n;i++){
            fill[i][0] = grid[i][0] + fill[i-1][0];
        }
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 || j == 0){
                    if(fill[i][j] <= k) count++;
                    continue;
                }
                fill[i][j] = fill[i][j-1] + fill[i-1][j] - fill[i-1][j-1] + grid[i][j];
                if(fill[i][j] <= k) count++;
            }
            // cout << endl;
        }
        return count;
    }
};

/*

7 9 18
8 15 24 
10 23 38 
*/