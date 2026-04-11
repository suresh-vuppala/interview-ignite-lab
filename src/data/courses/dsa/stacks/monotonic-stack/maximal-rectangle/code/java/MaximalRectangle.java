class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0) return 0;
        int n = matrix[0].length, maxArea = 0;
        int[] heights = new int[n];
        for (char[] row : matrix) {
            for (int j = 0; j < n; j++)
                heights[j] = row[j] == '1' ? heights[j] + 1 : 0;
            maxArea = Math.max(maxArea, largestRect(heights));
        }
        return maxArea;
    }
    private int largestRect(int[] h) {
        Deque<Integer> st = new ArrayDeque<>();
        int max = 0;
        for (int i = 0; i <= h.length; i++) {
            int cur = i == h.length ? 0 : h[i];
            while (!st.isEmpty() && cur < h[st.peek()]) {
                int height = h[st.pop()];
                int width = st.isEmpty() ? i : i - st.peek() - 1;
                max = Math.max(max, height * width);
            }
            st.push(i);
        }
        return max;
    }
}