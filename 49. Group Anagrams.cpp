#include "lib.h"

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string> > mp;
        for(int i=0;i<strs.size();i++){
            std::string temp = strs[i];
            std::sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
        }

        std::vector<std::vector<std::string>> res;
        for(const auto &it : mp){
            std::vector<std::string> temp;
            for(const auto &c : it.second){
                temp.push_back(c);
            }
            res.push_back(temp);
        }
        return res;
    }
};