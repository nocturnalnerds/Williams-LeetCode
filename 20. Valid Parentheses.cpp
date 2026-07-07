#include "lib.h"
class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> list;
        for(int i=0;i<s.length();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                list.push(s[i]);
            }else{
                if(list.empty()) return false;
                if(s[i] == ')' && list.top() == '('){
                    list.pop();
                }else if(s[i] == ']' && list.top() == '['){
                    list.pop();
                }else if(s[i] == '}' && list.top() == '{'){
                    list.pop();
                }else{
                    return false;
                }
            }
        }
        if(list.empty()) return true;
        else return false;
    }
};