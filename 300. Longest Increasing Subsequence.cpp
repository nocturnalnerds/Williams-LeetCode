#include "lib.h"

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        int dp[3000];
        for(int i=0;i<=n;i++) dp[i] = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    dp[i] = std::max(dp[i], dp[j]+1);
                }
            }
        }
        int ans = -1;
        for(int i=0;i<n;i++){
            ans = std::max(dp[i],ans);
        }
        return ans;
    }
};