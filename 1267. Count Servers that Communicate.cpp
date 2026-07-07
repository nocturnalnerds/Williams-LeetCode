#include "lib.h"

class Solution {
public:
    int count = 0;
    bool visited[255][255];
    int m, n;
    void linearScan(int r, int c, std::vector<std::vector<int>>&grid){
        int flag = 0;
        for(int i=0;i<n;i++){
            if(c == i) continue;
            if(grid[r][i] == 1 && visited[r][i] == 0){
                count++;
                flag = 1;
            }
            visited[r][i] = 1;
        }
        for(int j=0;j<m;j++){
            if(j == r) continue;
            if(grid[j][c] == 1 && visited[j][c] == 0){
                count++;
                flag = 1;
            }
            visited[j][c] = 1;
        }
    }
    int countServers(std::vector<std::vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    linearScan(i,j,grid);
                }
            }
        }
        return count;
    }
};