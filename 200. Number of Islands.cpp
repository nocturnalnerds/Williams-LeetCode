#include "lib.h"
class Solution {
public:
    bool visited[310][310];
    void dfs(int i, int j, std::vector<std::vector<char>>& grid){
        if(i == -1 || j == -1 || i >= grid.size() || j >= grid[0].size()) return;
        if (visited[i][j] || grid[i][j] == '0') return;
        visited[i][j] = true;
        dfs(i-1,j,grid);
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }

    int numIslands(std::vector<std::vector<char>>& grid) {
        memset(visited,0,sizeof(visited));
        int counter = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j] == false && grid[i][j] == '1'){
                    dfs(i,j,grid);
                    counter++;
                }
            }
        }
        
        return counter;
    }
};

/*

grid=[
["1","1","1","1","0"],
["1","1","0","1","0"],
["1","1","0","0","0"],
["0","0","0","0","0"]]

grid=[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]
*/