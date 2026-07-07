#include "lib.h"
class Solution {
public:
    std::vector<int> maxSubsequence(std::vector<int>& nums, int k) {
        std::vector<std::pair<int, int>> numsWithIndices;
        for (int i = 0; i < nums.size(); i++) {
            numsWithIndices.push_back({nums[i], i});
        }


        sort(numsWithIndices.begin(), numsWithIndices.end(),
             [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                 return a.first > b.first;
             });


        std::vector<std::pair<int, int>> topK(numsWithIndices.begin(), numsWithIndices.begin() + k);
        sort(topK.begin(), topK.end(),
             [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                 return a.second < b.second;
             });


        std::vector<int> result;
        for (auto& p : topK) {
            result.push_back(p.first);
        }

        return result;
    }
};