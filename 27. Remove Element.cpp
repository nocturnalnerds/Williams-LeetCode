#include "lib.h"
class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        std::vector<int> ans;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(ans[i] != val){
                nums[count] = ans[i];
                count++;
            }
        }
        return count;
    }
};