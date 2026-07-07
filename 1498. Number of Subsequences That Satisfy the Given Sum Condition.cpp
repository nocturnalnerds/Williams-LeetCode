#include "lib.h"

class Solution {
public:
    int numSubseq(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        const int mod = 1e9 + 7;
        int leftPtr = 0;
        int n = nums.size();
        int rightPtr = n-1;
        int cnt = 0;
        std::vector<int> binaryBit(n+1);
        binaryBit[0] = 1;
        for(int i=1;i<=n;i++){
            binaryBit[i] = (binaryBit[i-1] * 2) % mod;
        }

        while(leftPtr <= rightPtr){
            if(nums[leftPtr] + nums[rightPtr] <= target){
                cnt = (cnt + binaryBit[rightPtr - leftPtr]) % mod;
                leftPtr++;
            }else{
                rightPtr--;
            }
        }
        return cnt;
    }
};