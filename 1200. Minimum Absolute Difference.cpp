#include "lib.h"
#define pb push_back
class Solution {
public:
    std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr) {
        int mins = INT_MAX;
        std::vector<std::vector<int>> ans;
        sort(arr.begin(), arr.end());
        int i = 0;
        int j = 1;
        int diff = arr[j] - arr[i];
        ans.pb({arr[i], arr[j]});
        i++;
        j++;

        while(j < arr.size()){
            int curr = arr[j] - arr[i];
            if(curr < diff){
                ans.clear();
                diff = curr;
                ans.push_back({arr[i], arr[j]});
            }else if(diff == curr){
                ans.push_back({arr[i], arr[j]});
            }
            i++;
            j++;
        }
        return ans;
    }
};