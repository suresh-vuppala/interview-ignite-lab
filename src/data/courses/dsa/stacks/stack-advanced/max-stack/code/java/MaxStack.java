class MaxStack {
    Stack<Integer> st = new Stack<>();
    Stack<Integer> maxSt = new Stack<>();
    
    void push(int x) {
        st.push(x);
        if (maxSt.isEmpty() || x >= maxSt.peek()) maxSt.push(x);
    }
    
    void pop() {
        if (st.pop().equals(maxSt.peek())) maxSt.pop();
    }
    
    int top() {
        return st.peek();
    }
    
    int getMax() {
        return maxSt.peek();
    }
}