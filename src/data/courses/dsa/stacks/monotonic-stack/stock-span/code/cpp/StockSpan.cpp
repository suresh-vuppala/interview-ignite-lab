vector<int> stockSpan(vector<int>& prices) {
    int n = prices.size();
    vector<int> res(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && prices[st.top()] <= prices[i]) st.pop();
        res[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }
    return res;
}