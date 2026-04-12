class Solution:
    def minPathSum(self, grid) -> int:
        m,n=len(grid),len(grid[0]); dp=[0]*n
        for i in range(m):
            for j in range(n):
                if i==0 and j==0: dp[j]=grid[0][0]
                elif i==0: dp[j]=dp[j-1]+grid[i][j]
                elif j==0: dp[j]+=grid[i][j]
                else: dp[j]=grid[i][j]+min(dp[j],dp[j-1])
        return dp[-1]
