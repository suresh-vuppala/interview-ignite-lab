# ============================================================
# Spiral Matrix
# ============================================================

from typing import List

# ============================================================
# Solution 1: Simulation with Visited
# Time: O(M×N) | Space: O(M×N)
# ============================================================
class Solution1:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix), len(matrix[0])
        visited = [[False]*n for _ in range(m)]
        dirs = [(0,1),(1,0),(0,-1),(-1,0)]
        d, r, c, result = 0, 0, 0, []
        for _ in range(m*n):
            result.append(matrix[r][c]); visited[r][c] = True
            nr, nc = r+dirs[d][0], c+dirs[d][1]
            if nr<0 or nr>=m or nc<0 or nc>=n or visited[nr][nc]:
                d = (d+1)%4; nr, nc = r+dirs[d][0], c+dirs[d][1]
            r, c = nr, nc
        return result

# ============================================================
# Solution 2: Shrinking Boundaries (Optimal)
# Time: O(M×N) | Space: O(1) extra
# ============================================================
class Solution2:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        result = []
        top, bot = 0, len(matrix)-1
        left, right = 0, len(matrix[0])-1

        while top <= bot and left <= right:
            for j in range(left, right+1): result.append(matrix[top][j])
            top += 1
            for i in range(top, bot+1): result.append(matrix[i][right])
            right -= 1
            if top <= bot:
                for j in range(right, left-1, -1): result.append(matrix[bot][j])
                bot -= 1
            if left <= right:
                for i in range(bot, top-1, -1): result.append(matrix[i][left])
                left += 1

        return result
