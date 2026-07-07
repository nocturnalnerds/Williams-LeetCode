#include "lib.h"
class Solution {
public:
    int minimumCost(std::vector<int>& cost) {
        std::sort(cost.begin(), cost.end(), std::greater<int>());
        unsigned int res = 0;
        for(int i=0;i<cost.size();i++){
            if((i + 1) % 3 == 0) continue;
            res += cost[i];
        }
        return res;
    }
};


// 0 1 2 3 4 5