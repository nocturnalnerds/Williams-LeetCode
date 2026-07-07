#include "lib.h"
class Solution {
public:
    std::vector<int> vowelStrings(std::vector<std::string>& words, std::vector<std::vector<int>>& queries) {
        int n = words.size();
        int pref[n+1];
        int j = 0;
        for(const std::string &i : words){
            int k = i.length();
            if((i[0] == 'a' || i[0] == 'i' || i[0] == 'u' || i[0] == 'e' || i[0] == 'o') && (i[k-1] == 'a' || i[k-1] == 'i' || i[k-1] == 'u' || i[k-1] == 'e' || i[k-1] == 'o')){
                if(j == 0){
                    pref[j] = 1;
                }else{
                    pref[j] = pref[j-1] + 1;
                }
            }else{
                if(j == 0){
                    pref[j] = 0;
                }else{
                    pref[j] = pref[j-1];
                }
            }
            j++;
        }
        // cout << endl;
        std::vector<int> res;
        for(const auto &i : queries){
            if(i[0] == 0){
                res.push_back(pref[i[1]]);
            }else{
                res.push_back(pref[i[1]] -pref[i[0]-1]);
            }
            
        }
        return res;
    }
};