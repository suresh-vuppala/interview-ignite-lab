class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m, n = len(heights), len(heights[0])
        pac, atl = set(), set()
        def dfs(r, c, visit, prev):
            if r<0 or r>=m or c<0 or c>=n or (r,c) in visit or heights[r][c]<prev: return
            visit.add((r,c))
            for dr,dc in [(0,1),(0,-1),(1,0),(-1,0)]: dfs(r+dr,c+dc,visit,heights[r][c])
        for i in range(m): dfs(i,0,pac,0); dfs(i,n-1,atl,0)
        for j in range(n): dfs(0,j,pac,0); dfs(m-1,j,atl,0)
        return [[r,c] for r,c in pac & atl]