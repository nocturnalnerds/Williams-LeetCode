#include "lib.h"

class Solution {
public:
    const long long int MOD = 1e9 + 7;
    int numOfWays(int n) {
        int aba = 6;
        int abc = 6;
        for(int i = 2;i <= n; i++){
            long long int new_aba = (((aba%MOD) * 3LL)%MOD + ((abc%MOD) * 2LL)%MOD)%MOD;
            long long int new_abc = (((aba%MOD) * 2LL)%MOD + ((abc%MOD) * 2LL)%MOD)%MOD;
            aba = (new_aba) % MOD;
            abc = (new_abc) % MOD;
        }
        return (int)(aba + abc)%MOD;
    }
};

