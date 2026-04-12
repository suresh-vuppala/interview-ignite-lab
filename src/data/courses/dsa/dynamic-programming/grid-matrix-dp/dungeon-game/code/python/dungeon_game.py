class Solution:
    def calculateMinimumHP(self, dungeon) -> int:
        m,n=len(dungeon),len(dungeon[0])
        dp=[float('inf')]*(n+1); dp[n-1]=1
        for i in range(m-1,-1,-1):
            ndp=[float('inf')]*(n+1)
            for j in range(n-1,-1,-1):
                ndp[j]=max(1,min(dp[j],ndp[j+1])-dungeon[i][j])
            dp=ndp
        return dp[0]
