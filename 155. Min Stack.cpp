
#include "lib.h"
class MinStack {
public:
    
    std::stack<int> st;
    std::stack<int> minSt;

    
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();

    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};