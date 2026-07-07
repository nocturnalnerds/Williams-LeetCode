#include "lib.h"

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int sz = nums.size();
        std::vector<int> dp(sz+1);
        if(nums.size() == 1){
            return nums[0];
        }else if(nums.size() == 2){
            return std::max(nums[0],nums[1]);
        }
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0] + nums[2];
        for(int i=3;i<sz;i++){
            dp[i] = std::max(dp[i-2],dp[i-3]) + nums[i];
        }
        return std::max(dp[sz-1],dp[sz-2]);
    }
};

/*
2 7 9 3 1 10 4 7 12
i+2 , i+3
dp[0] = 2
dp[1] = 7
dp[2] = 11
dp[3] = 10
dp[4] = 12
dp[5] = 21
dp[6] = 14
dp[7] = 28
dp[8] = 33
*/

// H-2 . H-3
// 

// 1 2 3 1 
// 2 7 9 3 1
// 2 9 
// 7 3