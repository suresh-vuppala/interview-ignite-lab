class Solution:
    def longestPalindromeSubseq(self, s) -> int:
        r=s[::-1]; n=len(s); dp=[0]*(n+1)
        for i in range(1,n+1):
            prev=0
            for j in range(1,n+1):
                t=dp[j]; dp[j]=prev+1 if s[i-1]==r[j-1] else max(dp[j],dp[j-1]); prev=t
        return dp[n]
