int largestRectangle(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0, n = heights.size();
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            int h = heights[st.top()]; st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        st.push(i);
    }
    while (!st.empty()) {
        int h = heights[st.top()]; st.pop();
        int w = st.empty() ? n : n - st.top() - 1;
        maxArea = max(maxArea, h * w);
    }
    return maxArea;
}