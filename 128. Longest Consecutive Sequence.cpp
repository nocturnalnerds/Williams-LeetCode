#include "lib.h"

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::map<int,int> mp;
        if(nums.size() <= 1) return nums.size();
        for(const int &i : nums){
            mp[i]++;
        }
        int maks = 1;
        int it = 0;
        int bef = -1;
        bool first = true;
        for(const auto &[val, count] : mp){
            // cout << val << " " << count << endl;
            if(!first){
                bef = val;
                it = 1;
                maks = 1;
                first = false;
            }else{
                if(val - bef == 1){
                    it++;
                }else{
                    maks = std::max(maks,it);
                    it = 1;
                }
                bef = val;
            }
        }
        maks = std::max(maks, it);
        return maks;
    }
};