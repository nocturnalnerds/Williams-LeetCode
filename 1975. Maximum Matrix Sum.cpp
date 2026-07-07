#include "lib.h"
class Solution {
public:
    long long maxMatrixSum(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        int minAbs = INT_MAX;
        long long int sum = 0;
        unsigned int ct = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0){
                    ++ct;
                }
                minAbs = std::min(minAbs, abs(matrix[i][j]));
            }
        }
        if(ct % 2 == 1){
            sum -= 2 * minAbs;
        }
        return sum;
    }
};