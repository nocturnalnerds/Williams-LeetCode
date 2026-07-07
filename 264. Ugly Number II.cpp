#include "lib.h"
#define ll long long int

class Solution {
public:
    
    int nthUglyNumber(int n) {
        std::vector<ll> dp(n+1);
        dp[0] = 1;
        int i,j,k;
        i = j = k = 0;
        for(int it=1;it<n;it++){
            int kel2 = dp[i] * 2;
            int kel3 = dp[j] * 3;
            int kel5 = dp[k] * 5;
            
            dp[it] = std::min(kel2,std::min(kel3,kel5));
            if(kel2 == dp[it]) ++i;
            if(kel3 == dp[it]) ++j;
            if(kel5 == dp[it]) ++k;
        }
        // for(const auto &i : dp){
        //     cout << i << " ";
        // }
        // cout << endl;
        return dp[n-1];
    }
};

/*

O(N*log(N)) -> Merge Sort
priority_queue

1

2
  4
   8
   12
   20
  6
   
  10
3
  6
  9
  15
5
 10
 15
 25
 
 SET
 2^i * 3^j * 5^k


*/