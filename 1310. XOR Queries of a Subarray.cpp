#include "lib.h"

class Solution {
public:
    std::vector<int> xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries) {
        int pref[arr.size() + 3];
        pref[0] = arr[0];
        for(int i=1;i<arr.size();i++){
            pref[i] = pref[i-1] ^ arr[i];
        }
        std::vector<int> v;
        for(const auto &i : queries){
            int l = i[0];
            int r = i[1];
            if(l == 0){
                v.push_back(pref[r]);
            }else{
                v.push_back(pref[r] ^ pref[l-1]);
            }
        }
        return v;
    }
};