#include "lib.h"
class Solution {
public:
    int xorAllNums(std::vector<int>& nums1, std::vector<int>& nums2) {
        return ((nums2.size()&1)?std::accumulate(nums1.begin(),nums1.end(), 0, std::bit_xor<>{}):0)^((nums1.size()&1)?std::accumulate(nums2.begin(),nums2.end(), 0, std::bit_xor<>{}):0);
    }
};