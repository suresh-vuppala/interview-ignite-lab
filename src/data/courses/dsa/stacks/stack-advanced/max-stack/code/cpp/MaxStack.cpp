class MaxStack {
    stack<int> st, maxSt;
public:
    void push(int x) {
        st.push(x);
        if (maxSt.empty() || x >= maxSt.top()) maxSt.push(x);
    }
    
    void pop() {
        if (st.top() == maxSt.top()) maxSt.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMax() {
        return maxSt.top();
    }
};