#include "lib.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        std::vector<int>store;

        int ans1 = INT_MAX, cur, next, n;
        int last = head->val, position = 2;

        while(head->next){
            cur = head->val, next = head->next->val;

            if((last > cur and cur < next) or (last < cur and cur > next)) 
                store.push_back(position);
            position++;
            last = cur, head = head->next;

            n = store.size();
            if(n > 1) ans1 = std::min(ans1, store[n-1] - store[n-2]);
        }
        
        if(ans1 == INT_MAX) return {-1, -1};
        
        return {ans1, store.back() - store[0]};
    }
};

/*
 ListNode* prev = head;
        head = head->next;
        int i = 1, mindist = INT_MAX, prev_i = INT_MIN, first_i = -1;

        while (head->next != nullptr) {
            if ((prev->val < head->val && head->val > head->next->val) || 
                (prev->val > head->val && head->val < head->next->val)) {
                if (prev_i != INT_MIN) {
                    mindist = min(mindist, i - prev_i);
                }
                if (first_i == -1) {
                    first_i = i;
                }
                prev_i = i;
            }
            prev = head;
            head 
        if (mindist == INT_MAX) {
            return {-1, -1};
        }

        return {mindist, prev_i - first_i};
    }
*/