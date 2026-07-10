#include "lib.h"
// #include <bits/stdc++.h>
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tc;
    std::cin >> tc;
    while(tc--){
        int N;
        std::cin >> N;
        std::map<int,int> mp;
        int x;
        for(int i=0;i<N;i++){
            std::cin >> x;
            ++mp[x];
        }
        int group = 0;
        int carryOver = 0;
        // int cN = 1;
        for(const std::pair<const int, const int>& i : mp){
            if(i.first >= 0){
                // std::cout << group << " " << carryOver << '\n';
                group += (i.second + carryOver) / i.first;
                carryOver = (i.second + carryOver) % i.first;
                // ++cN;
            }
        }
        std::cout << group << '\n';
    }
    return 0;
}