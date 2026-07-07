#include "lib.h"

class Solution {
public:
    double averageWaitingTime(std::vector<std::vector<int>>& customers) {
        int summed_time = 0;
        double sum_avg = 0;
        for(const std::vector<int> &i : customers){
            summed_time = (std::max(summed_time, i[0]) + i[1]);
            sum_avg += summed_time - i[0];
        }
        return sum_avg/(double)customers.size();
    }
};