#include "lib.h"
class Solution {
public:
    bool isArraySpecial(std::vector<int>& nums) {
        if(nums.size() == 1) return true;
        if(nums.size() == 2) return ((nums[0] % 2 == 0 && nums[1] % 2 == 1) || (nums[0] % 2 == 1 && nums[1] % 2 == 0)) ? true : false;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1] % 2 == 0){
                if(nums[i] % 2 == 0) return false;
            }else{
                if(nums[i] % 2 == 1) return false;
            }
        }
        return true;
    }
};