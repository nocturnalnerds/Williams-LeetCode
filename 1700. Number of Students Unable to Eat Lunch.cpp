#include "lib.h"

class Solution {
public:
    int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
        int ones,zeros;
        ones = zeros = 0;
        for(const int &x : students){
            (x == 0) ? zeros++ : ones++;
        }
        for(const int &x : sandwiches){
            if(x == 0){
                if(zeros - 1 < 0) break;
                else --zeros;
            }else if(x == 1){
                if(ones - 1 < 0) break;
                else ones--;
            }
        }
        return ones + zeros;
    }
};