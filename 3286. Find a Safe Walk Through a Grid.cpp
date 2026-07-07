#include "lib.h"
#pragma GCC push_options                  
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx2,bmi,bmi2,lzcnt,popcnt")

#define fi first
#define se second

class Solution {
public:

    const int dx[4] = {0,0,1,-1};
    const int dy[4] = {1,-1,0,0};
    bool findSafeWalk(std::vector<std::vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> memo(m+1, std::vector<int>(n+1, (INT_MIN)));

        std::queue<std::pair<int,std::pair<int,int>>> q;
        q.push({health-grid[0][0], {0,0}});

        while(!q.empty()){
            std::pair<int,std::pair<int,int>> curr = q.front();
            q.pop();
            short h = curr.fi;
            short u = curr.se.fi;
            short v = curr.se.se;

            if(h < memo[u][v]) continue;

            for(short i=0;i<4;++i){
                short ix = u + dx[i];
                short iy = v + dy[i];

                if(ix >= 0 && ix < m && iy >= 0 && iy < n){
                    int updateH = h - grid[ix][iy];
                    if(updateH > memo[ix][iy]){
                        memo[ix][iy] = updateH;
                        q.push({updateH, {ix,iy}});
                    }
                }
            }
        }

        return (memo[m-1][n-1] >= 1);
    }
};

/*
[
[0,1,1,0,0,0],
[1,0,1,0,0,0],
[0,1,1,1,0,1],
[0,0,1,0,1,0]]

*/