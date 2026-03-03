int[] stockSpan(int[] prices) {
    int n = prices.length;
    int[] res = new int[n];
    Stack<Integer> st = new Stack<>();
    for (int i = 0; i < n; i++) {
        while (!st.isEmpty() && prices[st.peek()] <= prices[i]) st.pop();
        res[i] = st.isEmpty() ? i + 1 : i - st.peek();
        st.push(i);
    }
    return res;
}