#include "lib.h"

class Solution {
public:
    int maxScore(std::string s) {
        int n = s.size();
        int cnt1=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')cnt1++;
        }
        int temp0=0,temp1=cnt1,ans=INT_MIN;
        for(int i=0;i<n-1;i++){
            if(s[i]=='0'){
                temp0++;
            }
            else{
                temp1--;
            }
            int now = temp0+temp1;
                ans = std::max(ans,now);
        }
        return ans;
    }
};