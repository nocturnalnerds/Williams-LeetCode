#include "lib.h"
class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        std::priority_queue<int> q;
        for(const int &i : stones){
            q.push(i);
        }

        while(q.size() >= 2){
            int top1 = q.top();
            q.pop();
            int top2 = q.top();
            q.pop();
            if(top1 != top2){
                q.push(std::max(top1,top2) - std::min(top1,top2));
            }
        }
        if(q.size() == 0) return 0;
        else return q.top();
    }
};

