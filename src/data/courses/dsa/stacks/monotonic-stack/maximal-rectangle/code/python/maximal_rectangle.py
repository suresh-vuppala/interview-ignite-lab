# ============================================================
# Maximal Rectangle
# ============================================================

from typing import List

class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix: return 0
        C = len(matrix[0])
        heights = [0] * C
        max_area = 0
        for row in matrix:
            for j in range(C):
                heights[j] = heights[j] + 1 if row[j] == '1' else 0
            max_area = max(max_area, self.largest_rect(heights))
        return max_area

    def largest_rect(self, h):
        stack, max_a = [-1], 0
        for i in range(len(h) + 1):
            cur = h[i] if i < len(h) else 0
            while stack[-1] != -1 and cur <= h[stack[-1]]:
                ht = h[stack.pop()]
                max_a = max(max_a, ht * (i - stack[-1] - 1))
            stack.append(i)
        return max_a
