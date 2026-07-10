#include "lib.h"
#pragma GCC optimize ("O3")
class Solution {
public:
    std::vector<int> ans;
    void dfs(int u, std::vector<std::vector<int>> &adj, std::vector<bool> &vis){
        if(vis[u]) return;
        for(const int &i: adj[u]){
            if(!vis[i]) dfs(i, adj, vis);
        }
        vis[u] = true;
        ans.push_back(u);
        return;
    }
    
    bool checkCycle(int u, std::vector<std::vector<int>> &adj, std::vector<int> &state){
        if(state[u] == 1) return true;
        if(state[u] == 2) return false;
        state[u] = 1;
        for(const int &i : adj[u]){
            if(checkCycle(i, adj, state)) return true;
        }
        state[u] = 2;
        return false;
    }

    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        for(const std::vector<int> &i : prerequisites){
            int fi = i[0];
            int se = i[1];
            adj[fi].push_back(se);
        }
        std::vector<int> state(numCourses+1, 0);
        for(int i=0;i<numCourses;++i){
            if(checkCycle(i, adj, state)) return std::vector<int>();
        }

        std::vector<bool> vis(numCourses+1, false);
        for(int i=0;i<numCourses;++i){
            if(!vis[i]) dfs(i,adj,vis);
        }
        
        return ans;
    }
};