#include "lib.h"
class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        const int &n = piles.size();

        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end());
        int ans = 0;
        while(left <= right){
            int mid = left + (right - left)/2;
            long long int total  = 0;
            for(int i=0;i<n;i++){
                total += (long long int)ceil((double)piles[i]/(double)mid);
            }

            if(total <= h){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
};