#include "lib.h"
#define pb push_back
#define fi first
#define se second
class Solution {
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k) {
        std::vector<std::vector<std::pair<int,int>>> adj(n+1);  // {e, cost}
        for(const auto &e : flights){
            adj[e[0]].pb({e[1], e[2]});
        }

        std::vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;

        std::queue<std::pair<int, std::pair<int,int>>> q; // {stops, {node, cost}};
        q.push({0, {src, 0}});


        while(!q.empty()){
            std::pair<int,std::pair<int,int>> curr = q.front();
            q.pop();

            int stops = curr.fi;
            int nodec = curr.se.fi;
            int costc = curr.se.se;

            if(stops > k) continue;

            for(const auto &e : adj[nodec]){
                int vertex = e.fi;
                int pr = e.se;

                if(costc + pr < minCost[vertex]){
                    minCost[vertex] = costc + pr;
                    q.push({stops + 1, {vertex, minCost[vertex]}});
                }
            }
        }

        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};