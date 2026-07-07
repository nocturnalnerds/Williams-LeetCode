#include "lib.h"

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sumAll = n*(n+1)/2;
        int divByM = n/m;
        int sumByM = (divByM*(divByM+1)/2) * m;
        sumAll -= 2*sumByM;
        return sumAll;
    }
};