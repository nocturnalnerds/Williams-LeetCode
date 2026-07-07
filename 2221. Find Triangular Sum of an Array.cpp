#include "lib.h"

class Solution {
public:
    int triangularSum(std::vector<int>& nums) {
        int arr[1001][1001];
        const int n = nums.size();
        for(int i=0;i<n;i++){
            arr[0][i] = nums[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                arr[i+1][j] = (arr[i][j] + arr[i][j+1])%10;
            }
        }
        return arr[n-1][0];
    }
};