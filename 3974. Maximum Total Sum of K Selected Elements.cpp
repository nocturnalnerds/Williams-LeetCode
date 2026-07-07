#include "lib.h"
class Solution {
public:
    long long maxSum(std::vector<int>& nums, int k, int mul) {
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        int n = nums.size();
        long long int sum = 0;
        int i = 0;
        while(k){
            if(mul > 0) sum += (long long int)(1LL * nums[i] * mul);
            else sum += (long long int)nums[i];
            k--;
            mul--;
            i++;
        }
        return sum;
    }
};