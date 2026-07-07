#include "lib.h"

#define ll long long int
#define fi first
#define se second

class Solution {
public:
    std::vector<long long> minTimeMaxPower(int n, std::vector<std::vector<int>>& edges, int power, std::vector<int>& cost, int source, int target) {
        std::vector<std::vector<std::pair<int,int>>> adj(n+1);

        int edg = edges.size();
        for(int i=0;i<edg;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v,w});
        }

        std::priority_queue<std::pair<ll, std::pair<int,int>>, std::vector<std::pair<ll, std::pair<int,int>>>, std::greater<std::pair<ll, std::pair<int,int>>>> pq;

        std::vector<std::vector<ll>> dist(n, std::vector<ll>(power + 1, LLONG_MAX));

        pq.push({0, {source, power}});
        dist[source][power] = 0;

        while(!pq.empty()){
            auto tp = pq.top();
            ll time = tp.fi;
            ll node = tp.se.fi;
            ll remPower = tp.se.se;

            pq.pop();

            if(dist[node][remPower] < time) continue;
            if(remPower < cost[node]) continue;

            for (int j = 0; j < adj[node].size(); j++) {
                int adjacent = adj[node][j].fi;
                int wt = adj[node][j].se;

                ll newPower = remPower - cost[node];
                ll newTime = time + wt;

                if (newTime < dist[adjacent][newPower]) {
                    dist[adjacent][newPower] = newTime;
                    pq.push({newTime, {adjacent, newPower}});
                }
            }
        }

        long long bestTime = LLONG_MAX;
        int bestPower = -1;

        for (int p = 0; p <= power; p++) {
            if (dist[target][p] < bestTime) {
                bestTime = dist[target][p];
                bestPower = p;
            } else if (dist[target][p] == bestTime) {
                bestPower = std::max(bestPower, p);
            }
        }

        if (bestTime == LLONG_MAX)
            return {-1, -1};

        return {bestTime, bestPower};

    }
};