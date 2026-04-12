# ============================================================
# Pacific Atlantic Water Flow
# ============================================================
class Solution:
    def pacificAtlantic(self, heights):
        m, n = len(heights), len(heights[0])
        pac, atl = set(), set()
        def dfs(i, j, visited):
            visited.add((i, j))
            for di, dj in [(1,0),(-1,0),(0,1),(0,-1)]:
                ni, nj = i+di, j+dj
                if 0<=ni<m and 0<=nj<n and (ni,nj) not in visited and heights[ni][nj]>=heights[i][j]:
                    dfs(ni, nj, visited)
        for i in range(m): dfs(i, 0, pac); dfs(i, n-1, atl)
        for j in range(n): dfs(0, j, pac); dfs(m-1, j, atl)
        return list(pac & atl)
