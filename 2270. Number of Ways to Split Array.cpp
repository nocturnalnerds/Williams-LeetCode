#include "lib.h"

class Solution {
public:
    int waysToSplitArray(std::vector<int>& nums) {
        long long int sum = 0;
        for(int i : nums) sum += i;
        long long int l_sum = 0;
        int count = 0;
        for(int i=0;i<nums.size()-1;i++){
            l_sum += nums[i];
            sum -= nums[i];
            // std::cout << l_sum << " " << sum << '\n';
            if(l_sum >= sum) count++;
        }
        return count;
    }
};