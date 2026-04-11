class Solution:
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