# ============================================================
# Rotting Oranges
# ============================================================
from collections import deque
class Solution:
    def orangesRotting(self, grid) -> int:
        m, n, fresh, minutes = len(grid), len(grid[0]), 0, 0
        queue = deque()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2: queue.append((i, j))
                if grid[i][j] == 1: fresh += 1
        while queue and fresh > 0:
            minutes += 1
            for _ in range(len(queue)):
                r, c = queue.popleft()
                for dr, dc in [(1,0),(-1,0),(0,1),(0,-1)]:
                    nr, nc = r+dr, c+dc
                    if 0<=nr<m and 0<=nc<n and grid[nr][nc]==1:
                        grid[nr][nc] = 2; fresh -= 1; queue.append((nr, nc))
        return minutes if fresh == 0 else -1
