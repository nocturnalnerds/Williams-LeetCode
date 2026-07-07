#include "lib.h"

const int MOD = 1e9 + 7;

class Solution {
public:

    long long powMod(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    std::vector<int> productQueries(int n, std::vector<std::vector<int>>& queries) {
        std::vector<int> bits;  

        int bit = 0;
        int temp = n;
        while (temp > 0) {
            if (temp & 1) bits.push_back(bit);
            bit++;
            temp >>= 1;
        }
        
        int m = bits.size();
        std::vector<long long> pref(m + 1, 0);

        for (int i = 0; i < m; i++) {
            pref[i + 1] = pref[i] + bits[i];
        }
        
        std::vector<int> res;
        res.reserve(queries.size());

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long exp = pref[r + 1] - pref[l];  
            res.push_back(powMod(2, exp));
        }

        return res;
    }
};