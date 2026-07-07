#include "lib.h"

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        std::vector<std::vector<int>> visited = grid;
        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};
        std::queue<std::pair<int,int>> q;
        int fresh = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j] == 2) q.push({i,j});
                if(visited[i][j] == 1) fresh++;
            }
        }
        if(fresh == 0) return 0;
        if(q.empty()) return -1;
        int ans = -1;

        int min = -1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                const auto &[x,y] = q.front();
                int i,j;
                for(int k=0;k<4;k++){
                    i = x + dx[k];
                    j = y + dy[k];
                    if(i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 1){
                        visited[i][j] = 2;
                        fresh--;
                        q.push({i,j});
                    }
                }
                q.pop();
            }
            min++;
        }

        if(fresh == 0) return min;
        return -1;
        
    }
};