class MinStack {
    Stack<Integer> st = new Stack<>();
    Stack<Integer> minSt = new Stack<>();
    
    void push(int x) {
        st.push(x);
        if (minSt.isEmpty() || x <= minSt.peek()) minSt.push(x);
    }
    
    void pop() {
        if (st.pop().equals(minSt.peek())) minSt.pop();
    }
    
    int top() {
        return st.peek();
    }
    
    int getMin() {
        return minSt.peek();
    }
}