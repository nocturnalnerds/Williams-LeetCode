#include "lib.h"

class Solution {
public:
    int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
        std::vector<int> dp(367);
        dp[0] = 0;
        int days_it = 0;
        int i;
        for(i=1;i<=365 && days_it < days.size();i++){
            if(i != days[days_it]){
                dp[i] = dp[i-1];
            }else{
                dp[i] = std::min(dp[i-1] + costs[0], std::min(dp[std::max(0,i-7)] + costs[1], dp[std::max(0,i-30)] + costs[2]));
                days_it++;
            }
        }
        return dp[i-1];
    }
};