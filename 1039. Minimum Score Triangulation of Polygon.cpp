#include "lib.h"
class Solution {
public:
    bool canArrange(std::vector<int>& arr, int k) {
        int rem[k+1];   
        memset(rem,0,sizeof(rem));

        for(const int &i : arr){
            rem[(i % k) < 0 ? (i % k) + k : (i % k)]++;
        }

        if(rem[0] % 2 != 0) return false;
        for(int i=1;i <=k/2;i++){
            if(rem[i] != rem[k - i]){
                return false;
            }
        }
        return true;
    }
};