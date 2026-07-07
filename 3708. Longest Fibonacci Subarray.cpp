#include "lib.h"

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int len = 2;
        int maks = 0;
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            if(nums[i] + nums[i+1] == nums[i+2]){
                len++;
            }else{
                maks = std::max(maks, len);
                len = 2;
            }
        }
        maks = std::max(maks, len);
        return maks;
    }
};