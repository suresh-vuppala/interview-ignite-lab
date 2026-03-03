vector<int> prevGreater(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() <= arr[i]) st.pop();
        res[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return res;
}