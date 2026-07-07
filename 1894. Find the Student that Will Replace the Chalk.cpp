#include "lib.h"

#define lli long long int

class Solution {
public:
    int chalkReplacer(std::vector<int>& chalk, int k) {
        int n = chalk.size();
        lli sum = 0;
        for(const auto &i : chalk){
            sum += i;
        }
        lli left = k % sum;
        if(left == 0){
            return 0;
        }
        int pos = 0;
        for(const auto &i : chalk){
            if(left - i < 0){
                return pos;
            }
            left-=i;
            pos = (pos + 1) % n;
        }
        return pos;
    }
};