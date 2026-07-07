#include "lib.h"
class Solution {
public:
    struct Comparator {
    bool operator()(const std::pair<int,int>& a, const std::pair<int,int>& b) const {
            long long da = 1LL*a.first*a.first + 1LL*a.second*a.second;
            long long db = 1LL*b.first*b.first + 1LL*b.second*b.second;
            return da < db;
        }
    };
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, Comparator> pq;
        for (const auto &p : points) {
            int x = p[0], y = p[1];
            pq.push({x, y});
            if ((int)pq.size() > k) pq.pop();
        }
        std::vector<std::vector<int>> ans;
        ans.reserve(k);

        while (!pq.empty()) {
            auto [x, y] = pq.top();
            pq.pop();
            ans.push_back({x, y});
        }
        return ans;
    }
};