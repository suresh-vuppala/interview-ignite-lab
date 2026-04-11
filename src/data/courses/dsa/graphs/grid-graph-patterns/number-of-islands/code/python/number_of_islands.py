# ============================================================
# Number of Islands
# ============================================================
class Solution:
    def numIslands(self, grid) -> int:
        m, n, count = len(grid), len(grid[0]), 0
        def dfs(i, j):
            if i<0 or i>=m or j<0 or j>=n or grid[i][j]=='0': return
            grid[i][j] = '0'  # Sink
            dfs(i+1,j); dfs(i-1,j); dfs(i,j+1); dfs(i,j-1)
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1': count += 1; dfs(i, j)
        return count
