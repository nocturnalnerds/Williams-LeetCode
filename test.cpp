#include "lib.h"

int main(){
    std::string s;
    std::cin >> s;
    std::queue<char> q;
    q.push(s[0]);
    bool k = 0;
    for(const char &c : s){
        std::cout << "C: " << c << "\n";
        if(k == 0){
            k=1;
            continue;
        }
        if(!q.empty()){
            std::cout << "SINI\n";
            char tp = q.front();
            int tpi = tp-'a';
            char tippi = ((tpi+1)%26) + 'a';
            char tipmi = ((tpi-1+26)%26) + 'a';
            std::cout << tippi << " " << tipmi << "\n";
            if((tpi+1)%26 == (c - 'a') || ((tp-1))%26 == (c-'a')) q.pop();
            else q.push(c);
        }else q.push(c);
    }
    std::string ans = "";
    while(!q.empty()){
        ans += q.front();
        q.pop();
    }
    std::cout << ans << "\n";
}