#include "lib.h"
class Solution {
public:
    std::vector<std::vector<int>> filterOccupiedIntervals(std::vector<std::vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        
        for(const auto &i : occupiedIntervals){
            pq.push({i[0], i[1]});
        }

        int k = 0;
        std::vector<std::vector<int>> new_intervals;
        int prev_i = 0, prev_j = 0;
        while(!pq.empty()){
            const auto &[i,j] = pq.top();
            if(prev_i == 0 && prev_j == 0) {
                prev_i = i;
                prev_j = j;
                pq.pop();
                continue;
            }
            if(prev_j + 1 == i){
                prev_j = j;
                continue;
            }
            if(i > prev_j){
                new_intervals.push_back({prev_i, prev_j});
                prev_i = i;
                prev_j = j;
            }
            if(i <= prev_j && j >= prev_j){
                prev_j = j;
            }

            pq.pop();
        }
        new_intervals.push_back({prev_i, prev_j});

        std::vector<std::vector<int>> result;

        for (auto &it : new_intervals) {
            int &i = it[0];
            int &j = it[1];

            if (j < freeStart || i > freeEnd) {
                result.push_back({i, j});
            }
            else {
                if (i < freeStart) {
                    result.push_back({i, freeStart - 1});
                }
                if (j > freeEnd) {
                    result.push_back({freeEnd + 1, j});
                }
            }
        }

        return result;
    }
};