#include "lib.h"

class Solution {
public:
    int earliestFinishTime(std::vector<int>& landStartTime, std::vector<int>& landDuration, std::vector<int>& waterStartTime, std::vector<int>& waterDuration) {
        int32_t minn = std::numeric_limits<int>::max();
        for(const auto &[i,j] : std::views::zip(landStartTime, landDuration)){
            for(const auto &[k,l] : std::views::zip(waterStartTime, waterDuration)){
                int32_t curr = std::numeric_limits<int>::max();
                if(i+j >= k) curr = std::min(curr, i+j+l);
                if(k+l >= i) curr = std::min(curr, k+l+j);
                if(k+l < i) curr = std::min(curr, i+j);
                if(i+j < k) curr = std::min(curr, k+l);
                // cout << i << " " << j << " " << k << " " << l << " " << curr << "\n";
                minn = std::min(curr, minn);
            }
        }
        return minn;
    }
};


/*

5 3 

9 10

*/