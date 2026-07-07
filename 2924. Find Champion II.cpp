#include "lib.h"
class Solution {
    public:
    int findChampion(int n, std::vector<std::vector<int>>& edges) {
        if(n == 1) return 0;
        int counter[n+1];
        memset(counter,0,sizeof(counter));
        for(const auto &i : edges){
            ++counter[i[1]];
        }
        int ans = -1;
        for(int i=0;i<n;i++){
            if(counter[i] == 0){
                if(ans == -1) ans = i;
                else return -1;
            }
        }
        return ans;
    }
};