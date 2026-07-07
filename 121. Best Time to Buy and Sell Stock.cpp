#include "lib.h"

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int maks = -1;
        int left = 1e9;
        int curr_maks = 0;
        for(int i=0;i<prices.size();i++){
            if(prices[i] < left){
                left = prices[i];
                maks = std::max(curr_maks, maks);
                curr_maks = 0;
            }else{
                curr_maks = std::max(curr_maks, prices[i] - left);
                maks = std::max(curr_maks, maks);
            }
        }
        return maks;
    }
};