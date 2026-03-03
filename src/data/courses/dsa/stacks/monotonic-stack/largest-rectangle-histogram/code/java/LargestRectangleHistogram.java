int largestRectangle(int[] heights) {
    Stack<Integer> st = new Stack<>();
    int maxArea = 0, n = heights.length;
    for (int i = 0; i < n; i++) {
        while (!st.isEmpty() && heights[st.peek()] > heights[i]) {
            int h = heights[st.pop()];
            int w = st.isEmpty() ? i : i - st.peek() - 1;
            maxArea = Math.max(maxArea, h * w);
        }
        st.push(i);
    }
    while (!st.isEmpty()) {
        int h = heights[st.pop()];
        int w = st.isEmpty() ? n : n - st.peek() - 1;
        maxArea = Math.max(maxArea, h * w);
    }
    return maxArea;
}