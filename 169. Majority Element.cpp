#include "lib.h"

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int major = nums.size() / 2;
        std::sort(nums.begin(),nums.end());
        return nums[major];
    }
};