class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix: return 0
        n = len(matrix[0])
        heights = [0] * n
        max_area = 0
        for row in matrix:
            for j in range(n):
                heights[j] = heights[j] + 1 if row[j] == '1' else 0
            max_area = max(max_area, self.largestRect(heights))
        return max_area
    
    def largestRect(self, h):
        stack, max_area = [], 0
        for i in range(len(h) + 1):
            cur = h[i] if i < len(h) else 0
            while stack and cur < h[stack[-1]]:
                height = h[stack.pop()]
                width = i if not stack else i - stack[-1] - 1
                max_area = max(max_area, height * width)
            stack.append(i)
        return max_area