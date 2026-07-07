#include "lib.h"
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int n = arr.size();
        int maks = 1;
        arr[0] = 1;
        for(int i=1;i<n;i++){
            if(arr[i] - arr[i-1] > 1){
                arr[i] = arr[i-1]++;
                maks = arr[i];
            }
            maks = std::max(maks, arr[i]);
        }
        return maks;
    }
};