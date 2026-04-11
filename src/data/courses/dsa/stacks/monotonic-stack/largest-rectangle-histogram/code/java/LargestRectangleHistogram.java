// ============================================================
// Largest Rectangle in Histogram
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Brute Force
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
    public int largestRectangleArea(int[] h) {
        int max = 0;
        for (int i = 0; i < h.length; i++) {
            int min = h[i];
            for (int j = i; j < h.length; j++) {
                min = Math.min(min, h[j]);
                max = Math.max(max, min * (j - i + 1));
            }
        }
        return max;
    }
}

// ============================================================
// Solution 2: Monotonic Stack (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
    public int largestRectangleArea(int[] heights) {
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(-1);
        int max = 0;

        for (int i = 0; i <= heights.length; i++) {
            int h = (i == heights.length) ? 0 : heights[i];
            while (stack.peek() != -1 && h <= heights[stack.peek()]) {
                int height = heights[stack.pop()];
                int width = i - stack.peek() - 1;
                max = Math.max(max, height * width);
            }
            stack.push(i);
        }

        return max;
    }
}
