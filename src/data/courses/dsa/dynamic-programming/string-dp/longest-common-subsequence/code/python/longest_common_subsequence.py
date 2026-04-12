class Solution:
    def longestCommonSubsequence(self, t1, t2) -> int:
        m,n=len(t1),len(t2); dp=[0]*(n+1)
        for i in range(1,m+1):
            prev=0
            for j in range(1,n+1):
                temp=dp[j]
                dp[j]=prev+1 if t1[i-1]==t2[j-1] else max(dp[j],dp[j-1])
                prev=temp
        return dp[n]
