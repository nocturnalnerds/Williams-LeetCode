#include "lib.h"

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        const int &n = nums.size();
        if (n == 0) return {-1, -1};

        int left = 0, right = n - 1, first = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            if (nums[mid] == target) first = mid;
        }

        if (first == -1) return {-1, -1};

        left = 0; 
        right = n - 1;
        int last = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            if (nums[mid] == target) last = mid;
        }

        return {first, last};
    }
};