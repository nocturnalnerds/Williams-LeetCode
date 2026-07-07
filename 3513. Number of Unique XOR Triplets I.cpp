#include "lib.h"

class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;

        int count = 0;
        int temp = n;
        while(temp > 0){
            count++;
            temp >>= 1;
        }
        return pow(2,count);
    }
};

