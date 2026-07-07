#include "lib.h
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0;
        int k = 0;
        long long sum = 0;
        while(n > 0){
            int dig = n % 10;
            n /= 10;
            if(dig != 0){
                num += (std::pow(10,k) * dig);
                sum += dig;
                k++;
            }
        }
        return (long long)num * sum;
    }
};