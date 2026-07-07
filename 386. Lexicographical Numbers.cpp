#include "lib.h"

class Solution {
public:
    void rec(int curr, int n, std::vector<int>&res){
        if(curr > n) return;
        res.push_back(curr);
        for(int i=0;i<=9;i++){
            int new_num = curr * 10 + i;
            if(new_num <= n){
                rec(new_num,n,res);
            }else{
                break;
            }
        }
    }
    std::vector<int> lexicalOrder(int n) {
        std::vector<int> hasil;
        for(int i=1;i<=9;i++){
            rec(i,n,hasil);
        }
        return hasil;
    }
};