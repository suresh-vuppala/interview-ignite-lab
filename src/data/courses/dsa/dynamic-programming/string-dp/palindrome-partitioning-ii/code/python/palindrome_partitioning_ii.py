class Solution:
    def minCut(self,s)->int:
        n=len(s);pal=[[False]*n for _ in range(n)]
        for i in range(n-1,-1,-1):
            for j in range(i,n):pal[i][j]=(s[i]==s[j]) and (j-i<3 or pal[i+1][j-1])
        dp=list(range(n))
        for i in range(n):
            if pal[0][i]:dp[i]=0
            else:
                for j in range(1,i+1):
                    if pal[j][i]:dp[i]=min(dp[i],dp[j-1]+1)
        return dp[-1]