#include "lib.h"
class Solution {
public:
    int minimumPushes(std::string word) {
        std::map<char, int> mp;
        for (const char &i : word) {
            mp[i]++;
        }

        std::vector<std::pair<char, int>> freq(mp.begin(), mp.end());

        sort(freq.begin(), freq.end(), [](std::pair<char,int> &a, std::pair<char,int> &b) {
            return a.second > b.second;
        });

        int k = 1;
        int count = 0;

        for (const std::pair<char,int> &i : freq) {
            count += (ceil(k++ / 8.0) * i.second);
        }
        return count;
    }
};