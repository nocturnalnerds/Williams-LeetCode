#include "lib.h"
class Solution {
public:
    std::vector<int> pivotArray(std::vector<int>& nums, int pivot) {
        std::vector<int> left;
        std::vector<int> mid;
        std::vector<int> right;

        for(const auto &i : nums){
            if(i < pivot) left.push_back(i);
            else if( i > pivot) right.push_back(i);
            else mid.push_back(i);
        }
        std::vector<int> ans;
        for(const auto &i : left) ans.push_back(i);
        for(const auto &i : mid) ans.push_back(i);
        for(const auto &i : right) ans.push_back(i);

        return ans;
    }
};