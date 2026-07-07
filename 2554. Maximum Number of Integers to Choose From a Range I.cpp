#include "lib.h"

class Solution {
public:
    int maxCount(std::vector<int>& banned, int n, int maxSum) {
        std::unordered_map<int,int> mp;
        for(const int &i : banned){
            mp[i] = 1;
        }
        int cur_sum = 0;
        int count = 0;
        for(int i=1;i<=n;i++){
            if(mp[i] != 1 && cur_sum + i <= maxSum){
                cur_sum += i;
                count++;
            }
        }
        return count;
    }
};

// 1, 6, 5
// 1,2,3,4,5