#include "lib.h"

class Solution {
public:
    long long maxSubarraySum(std::vector<int>& nums, int k) {
        bool plus = false;
        for(auto &i : nums){
            if(i >= 0){
                plus = true;
                break;
            }
        }
        const int &n = nums.size();
        int curr = 0;
        int maks;
        if(plus){
            maks = -1;
            for(int i=0;i<n;i++){
                if(nums[i] > 0){
                    curr += (nums[i] * k);
                }else{
                    maks = std::max(maks,curr);
                    curr = 0;
                }
            }
            maks = std::max(maks,curr);
        }else{
            maks = INT_MIN;
            for(int i=0;i<n;i++){
                if(nums[i] == 0) maks = 0;
                else{
                    int curr = nums[i]/k;
                    maks = std::max(maks, curr);
                }
            }
        }

        return maks;
    }
};