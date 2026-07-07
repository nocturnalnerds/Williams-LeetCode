#include "lib.h"
class Solution {
public:
    std::vector<int> sortJumbled(std::vector<int>& mapping, std::vector<int>& nums) {
        std::vector<std::pair<int, int>> storePairs;

        for (int i = 0; i < nums.size(); ++i) {
            std::string number = std::to_string(nums[i]);
            std::string formed = "";
            for (int j = 0; j < number.size(); ++j) {
                formed = formed + (std::to_string(mapping[number[j] - '0']));
            }

            int mappedValue = std::stoi(formed);

            storePairs.push_back({mappedValue, i});
        }

        sort(storePairs.begin(), storePairs.end());
        std::vector<int> answer;
        for (const auto &pair : storePairs) {
            answer.push_back(nums[pair.second]);
        }
        return answer;
    }
};