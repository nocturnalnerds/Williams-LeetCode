#include "lib.h"

#define lli long long int
class Solution {
public:
    long long getDescentPeriods(std::vector<int>& prices) {
        lli sum = prices.size();
        lli len = 0;
        for(int i=0;i<prices.size() - 1;i++){
            if(prices[i] - 1 == prices[i+1]){
                len++;
            }else{
                sum += (len*(len+1))/2;
                len = 0;
            }
        }
        sum += (len * (len + 1)) / 2;
        return sum;
    }
};

// 5 4 3 2 1