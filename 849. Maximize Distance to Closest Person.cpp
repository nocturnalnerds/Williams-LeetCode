#include "lib.h"

class Solution {
public:
    int maxDistToClosest(std::vector<int>& seats) {
        int n = seats.size();
        int left_side = -1;
        for(int i=0;i<n;i++){
            if(seats[i] == 1){
                left_side = i;
                break;
            }
        }
        std::vector<int> fromLeft(n+1, 0);
        if(left_side != n-1){
            for(int i=left_side;i<n;i++){
                if(seats[i] == 1){
                    left_side = i;
                    fromLeft[i] = -1;
                }else{
                    fromLeft[i] = i - left_side;
                }
            }
        }
        int right_side = n;
        for(int i=n-1;i>=0;i--){
            if(seats[i] == 1){
                right_side = i;
                break;
            }
        }
        std::vector<int> fromRight(n+1,0);
        if(right_side != 0){
            for(int i=right_side;i>=0;i--){
                if(seats[i] == 1){
                    right_side = i;
                    fromRight[i] = -1;
                }else{
                    fromRight[i] = right_side - i;
                }
            }
        }
        int ans = -1;
        // for(int i=0;i<n;i++){
        //     cout << fromLeft[i] << " ";
        // }
        // cout << "\n";
        // for(int i=0;i<n;i++){
        //     cout << fromRight[i] << " ";
        // }
        for(int i=0;i<n;i++){
            if(fromLeft[i] == -1 || fromRight[i] == -1) continue;
            if(fromLeft[i] != 0 && fromRight[i] != 0) ans = std::max(ans,std::min(fromLeft[i], fromRight[i]));
            else{
                ans = std::max(ans, std::max(fromLeft[i], fromRight[i]));
            }
        }
        return ans;
    }
};

/*
   1 0 0 0 1 0 1
   -1 1 2 3 -1 0 -1
   -1 3 2 1 -1 0 -1

   1 0 0 0
   -1 1 2 3
   -1 
*/