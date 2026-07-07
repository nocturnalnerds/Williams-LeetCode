#include "lib.h"
class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = height.size();
        int Left[n+1], Right[n+1];
        memset(Left,0,sizeof(Left));
        memset(Right,0,sizeof(Right));

        int highest_Left = -1;
        for(int i=0;i<n;i++){
            if(height[i] > highest_Left){
                highest_Left = height[i];
            }
            Left[i] = highest_Left;
        }
        
        int highest_Right = -1;
        for(int i=n-1;i>=0;i--){
            if(height[i] > highest_Right){
                highest_Right = height[i];
            }
            Right[i] = highest_Right;
        }
        int res = 0;
        for(int i=0;i<n;i++){
            res += std::min(Left[i], Right[i]) - height[i];
        }
        return res;
    }
};