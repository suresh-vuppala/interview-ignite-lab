class Solution:
    def cherryPickup(self, grid) -> int:
        n=len(grid)
        dp=[[[-1]*n for _ in range(n)] for _ in range(n)]
        dp[0][0][0]=grid[0][0]
        for r1 in range(n):
            for c1 in range(n):
                for r2 in range(n):
                    c2=r1+c1-r2
                    if c2<0 or c2>=n or grid[r1][c1]==-1 or grid[r2][c2]==-1: continue
                    v=grid[r1][c1]+(grid[r2][c2] if r1!=r2 else 0)
                    best=-1
                    for pr1,pc1 in [(r1-1,c1),(r1,c1-1)]:
                        for pr2,pc2 in [(r2-1,c2),(r2,c2-1)]:
                            if pr1>=0 and pc1>=0 and pr2>=0 and pc2>=0 and dp[pr1][pc1][pr2]>=0:
                                best=max(best,dp[pr1][pc1][pr2])
                    if best>=0 or (r1==0 and c1==0 and r2==0): dp[r1][c1][r2]=v+max(0,best)
        return max(0,dp[n-1][n-1][n-1])
