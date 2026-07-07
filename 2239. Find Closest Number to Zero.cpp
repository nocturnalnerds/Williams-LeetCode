#include "lib.h"

class Solution {
public:
    int findClosestNumber(std::vector<int>& nums) {
        int ans = 0;
        int prevMinDist = INT_MAX;
        for(const auto &i : nums){
            int curr = std::abs(i);
            std::cout << curr << '\n';
            if(curr <= prevMinDist){
                ans = (std::abs(ans) == curr) ? std::max(ans, i) : i;
                prevMinDist = curr;
            }
        }
        return ans;
    }
};