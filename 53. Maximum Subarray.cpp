#include "lib.h"
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int maks = -1e9;
        int temp = 0;
        int start = 0, end = 0;
        int s = 0;
        for(int i=0;i<nums.size();i++){
            temp += nums[i];
            if(maks < temp){
                maks = temp;
                start = s;
                end = i;
            }
            if(temp < 0){
                temp = 0;
                s = i + 1;
            }
        }
        std::cout << start << " " << end << '\n';
        return maks;
    }
};

/*    -2, 1, -3, 4, -1, 2, 1, -5, 4
maks   -2 1   1. 4   4  5  6.  6  6
temp = -2 1.  0  4   3  5  6   1  5
*/