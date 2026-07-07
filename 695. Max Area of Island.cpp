#include "lib.h"

#include <cstring>
class Solution {
public:
    bool visited[100][100];
    int n,m;
    int curr_counter = 0;
    void dfs(int i, int j, std::vector<std::vector<int>>& grid){
        if(i == -1 || j == -1 || i >= n || j >= m) return;
        if(grid[i][j] == 0 || visited[i][j]) return;

        visited[i][j] = true;
        curr_counter++;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        memset(visited,0,sizeof(visited));
        n = grid.size();
        m = grid[0].size();

        int maks = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    curr_counter = 0;
                    dfs(i,j,grid);
                    maks = std::max(curr_counter,maks);
                }
            }
        }
        return maks;

    }
};

/*

grid=[
    [0,0,1,0,0,0,0,1,0,0,0,0,0],
    [0,0,0,0,0,0,0,1,1,1,0,0,0],
    [0,1,1,0,1,0,0,0,0,0,0,0,0],
    [0,1,0,0,1,1,0,0,1,0,1,0,0],
    [0,1,0,0,1,1,0,0,1,1,1,0,0],
    [0,0,0,0,0,0,0,0,0,0,1,0,0],
    [0,0,0,0,0,0,0,1,1,1,0,0,0],
    [0,0,0,0,0,0,0,1,1,0,0,0,0]
]

*/