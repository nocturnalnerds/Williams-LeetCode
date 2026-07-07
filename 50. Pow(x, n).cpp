#include "lib.h"
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        bool flag = false;
        long copy_n = n;
        if(copy_n < 0){
            flag = 1;
            copy_n *= -1;
        }
        while(copy_n!=0){
            if(copy_n & 1){
                res *= x;
                copy_n -=1;
            }else{
                x *= x;
                copy_n /= 2;
            }
        }
        return (flag) ? 1/res : res;
    }
};