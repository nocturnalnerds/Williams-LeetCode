#include "lib.h"

class Solution {
public:
    int largestProperDivisor(int n) {
        if (n <= 1) {
            return 0; 
        }

        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return n / i; 
            }
        }
        return 1;
    }
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        bool flag = false;
        for(int i=1;i<n;i++){
            if(nums[i] > prev){
                prev = nums[i];
            }else{
                flag = true;
            }
        }
        prev = nums[n-1];
        int cnt = 0;
        for(int i=n-2;i>=0;i--){
            if(nums[i] > prev){
                int lpd = largestProperDivisor(nums[i]);
                if(lpd == 1) return -1;
                if(nums[i]/lpd > prev) {
                    int lpd2nd = largestProperDivisor(nums[i]/lpd);
                    if(lpd2nd == 1) return -1;
                    if(nums[i]/lpd/lpd2nd <= prev){
                        cnt+=2;
                        nums[i] = nums[i]/lpd/lpd;
                    }
                }
                else{
                    nums[i] /= lpd;
                    cnt++;
                }
            }
            prev = nums[i];
        }
        return cnt;
    }
};