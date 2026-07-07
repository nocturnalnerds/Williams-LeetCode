#include "lib.h"

class Solution {
public:
    int memo[100];
    int climbStairs(int n) {
        if(n <= 1) return 1;
        if(memo[n] != 0) return memo[n];
        else return memo[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};