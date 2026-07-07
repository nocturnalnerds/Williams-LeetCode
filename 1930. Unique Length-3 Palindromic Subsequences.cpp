#include "lib.h"

class Solution {
public:
    int countPalindromicSubsequence(std::string s) {
        int Res=0;
        std::vector<int> fc(26, s.length());
        std::vector<int> lc(26);

        for(int i=0;i<s.length();i++) {
            int index = s[i]-'a';
            fc[index] = std::min(fc[index], i);
            lc[index] = i;
        }

        for(int i =0;i<26;i++) {
            //if fc[i] and lc[i] are not same, then there are more than one occurance of that charecter
            if(fc[i]<lc[i]) {
                //adding the no of unique charecters between them form subsequences
                Res += std::unordered_set<int>(s.begin()+fc[i]+1,s.begin()+lc[i]).size();
            }
        }
        return Res;
    }
};