#include "lib.h"
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for (int i = 0; i <= std::min(limit, n); i++) {
            if (n - i > 2 * limit) {
                continue;
            }
            ans += std::min(n - i, limit) - std::max(0, n - i - limit) + 1;
        }
        return ans;
    }
};