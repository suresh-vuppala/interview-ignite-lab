class Solution {
public:
    // O(m*n) — Build histogram per row, apply largest rectangle in histogram
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), maxArea = 0;
        vector<int> heights(n, 0);
        
        for (int i = 0; i < m; i++) {
            // Build histogram heights
            for (int j = 0; j < n; j++)
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
    
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        int maxArea = 0, n = h.size();
        for (int i = 0; i <= n; i++) {
            int cur = (i == n) ? 0 : h[i];
            while (!st.empty() && cur < h[st.top()]) {
                int height = h[st.top()]; st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};