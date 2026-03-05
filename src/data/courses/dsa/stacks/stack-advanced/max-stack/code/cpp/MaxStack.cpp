#include <stack>
#include <algorithm>
using namespace std;

class MaxStack {
private:
    stack<int> st;
    stack<int> maxSt;
    
public:
    MaxStack() {}
    
    void push(int x) {
        st.push(x);
        if (maxSt.empty()) {
            maxSt.push(x);
        } else {
            maxSt.push(max(x, maxSt.top()));
        }
    }
    
    int pop() {
        maxSt.pop();
        int val = st.top();
        st.pop();
        return val;
    }
    
    int top() {
        return st.top();
    }
    
    int getMax() {
        return maxSt.top();
    }
};
