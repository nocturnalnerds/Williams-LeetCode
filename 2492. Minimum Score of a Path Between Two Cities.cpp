#include "lib.h"
#define pb push_back
class Solution {
public:
    int minScore(int n, std::vector<std::vector<int>>& roads) {
        std::vector<std::vector<std::pair<int,int>>> adj(n+1);

        for(const auto &e : roads){
            adj[e[0]].pb({e[1], e[2]});
            adj[e[1]].pb({e[0], e[2]});
        }

        std::vector<int> vis(n+1,0);
        std::queue<int> q;
        q.push(1);
        vis[1] = 1;

        int32_t ans = INT_MAX;

        while(!q.empty()){
            const int u = q.front();
            q.pop();

            for(const auto &[v,w] : adj[u]){
                ans = std::min(ans, w);
                if(!vis[v]){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};