#include "lib.h"

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        int n = nums.size();
        std::unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(mp[nums[i]] >= 1) return true;
            else{
                mp[nums[i]]++;
            }
        }
        return false;
    }
};