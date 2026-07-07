#include "lib.h"

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int len = nums.size();
        std::map<int,int> mp;
        std::map<int,int> index;
        for(int i=0;i<len;i++){
            mp[nums[i]] = 1;
            index[nums[i]]= i;
        }
        for(int i=0;i<len;i++){
            int cek = target - nums[i];
            if(mp[cek] == 1){
                int j = index[cek];
                if(j == i) continue;
                else return {i,j};
            }
        }
        return {};
    }
};