#include "lib.h"

class Solution {
public:
    std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) {
        std::map<int, bool> mA,mB;
        std::vector<int> res;
        for(int i=0;i<A.size();i++){
            mA[A[i]] = true;
            mB[B[i]] = true;
            int count = 0;
            for(int j=0;j<=i;j++){
                if((mA[A[j]] == true && mB[A[j]] == true )){
                    count++;
                }
            }
            res.push_back(count);
        }
        return res;
    }
};