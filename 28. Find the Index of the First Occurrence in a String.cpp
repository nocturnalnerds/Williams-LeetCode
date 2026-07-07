#include "lib.h"

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int n = needle.length(), m = haystack.length();
        if(n == 0) return 0;
        if(m < n) return -1;
        for(int i = 0; i<=(m-n);i++){
            bool cek = true;
            int indx; 
            for(int j = 0; j<n; j++){
                if(needle[j] !=haystack[j+i]){
                    cek = false;
                    break;
                }
                indx = i;
            }
            if(cek) return indx;
        }
        return -1;
    }
};