# ============================================================
# Largest Rectangle in Histogram
# ============================================================

from typing import List

# ============================================================
# Solution 1: Brute Force
# Time: O(N²) | Space: O(1)
# ============================================================
class Solution1:
    def largestRectangleArea(self, heights: List[int]) -> int:
        max_area = 0
        for i in range(len(heights)):
            min_h = heights[i]
            for j in range(i, len(heights)):
                min_h = min(min_h, heights[j])
                max_area = max(max_area, min_h * (j - i + 1))
        return max_area

# ============================================================
# Solution 2: Monotonic Increasing Stack (Optimal)
# Time: O(N) | Space: O(N)
# ============================================================
class Solution2:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = [-1]  # Left sentinel
        max_area = 0

        for i in range(len(heights) + 1):
            # Height 0 at end forces remaining bars to pop
            h = heights[i] if i < len(heights) else 0

            while stack[-1] != -1 and h <= heights[stack[-1]]:
                height = heights[stack.pop()]
                width = i - stack[-1] - 1
                max_area = max(max_area, height * width)

            stack.append(i)

        return max_area
