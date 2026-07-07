#include "lib.h"
class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int flag = 0;
        int maks = -1;
        for(int i = 0; i < nums.size();i++){
            maks = std::max(nums[i], maks);
        }
        int curr_len = -1;
        int len = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == maks){
                len++;
            }else{
                curr_len = std::max(len, curr_len);
                len = 0;
            }
        }
        curr_len = std::max(len, curr_len);
        return curr_len;
    }
};

/*




*/