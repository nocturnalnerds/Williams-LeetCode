#include "lib.h"
class Solution {
public:
    double averageWaitingTime(std::vector<std::vector<int>>& customers) {
        double wait = (customers[0][0] + customers[0][1]) - customers[0][0];
        double prev_sum = customers[0][0] + customers[0][1];
        for(int i = 1; i < customers.size();i++){
            if(prev_sum >= customers[i][0]){
                prev_sum = (prev_sum + customers[i][1]);
                wait += (prev_sum - customers[i][0]);
                
            }else{
                wait += customers[i][1];
                prev_sum = customers[i][0] + customers[i][1];
            }
        }
        
        double ans = wait / (double)customers.size();
        return ans;
    }
};

/*

[[5,2],[5,4],[10,3],[20,1]]

2

5 6 7 8 9 10 11

*/