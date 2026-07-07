#include "lib.h"

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        const auto swap = [](int *a, int *b) -> void {
            int temp = *a;
            *a = *b;
            *b = temp;
        };
        
        const int n = nums.size();
        int k = 0;
        for(int i=0;i<n;++i){
            if(nums[i] != 0) {swap(&nums[i], &nums[k]); k++;}
        }
    }
};