class Solution:
    def maxPathSum(self, mat):
        m,n=len(mat),len(mat[0]); dp=mat[0][:]
        for i in range(1,m):
            ndp=[0]*n
            for j in range(n):
                best=dp[j]
                if j>0: best=max(best,dp[j-1])
                if j<n-1: best=max(best,dp[j+1])
                ndp[j]=mat[i][j]+best
            dp=ndp
        return max(dp)
