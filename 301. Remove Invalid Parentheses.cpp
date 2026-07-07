#include "lib.h"


class Solution {
public:
    int getMin(std::string str){
        std::stack<char> st;
        for(int i=0;i<str.length();i++){
            char ch = str[i];
            if(ch == '('){
                st.push(ch);
            }else if(ch == ')'){
                if(st.size() == 0) st.push(ch);
                else if(st.top() == ')') st.push(ch);
                else if(st.top() == '(') st.pop();
            }
        }
        return st.size();
    }
    // cek kalau udah visited
    // USE BFS
    void solve(std::string s, int mra, std::unordered_set<std::string>&set, std::unordered_set<std::string>&vis){
        if(vis.find(s) != vis.end()) return;
        
        vis.insert(s);
        if(mra == 0){
            int mrnow = getMin(s);
            if(mrnow == 0){
                set.insert(s);
            }       
            return ;
        }
        for(int j = 0;j < s.length();j++){
            // cek pakai two pointer; ( left & right)
            std::string left = s.substr(0,j);
            std::string right = s.substr(j+1);
            solve(left + right, mra - 1, set, vis);
            
        }
    }
    std::vector<std::string> removeInvalidParentheses(std::string s) {
        //harusnya udah selesai di sini....
        int mins = getMin(s);//selesai in ini dulu
        std::vector<std::string> ans;
        std::unordered_set<std::string>st;// cari unique string // jangan di address dulu
        std::unordered_set<std::string>vis;//buat bfsnya nanti
        solve(s, mins,st,vis);
        for(auto x : st) ans.push_back(x);
        return ans;
    }
};