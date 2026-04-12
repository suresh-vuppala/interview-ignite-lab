class Solution:
    def minDistance(self, w1, w2) -> int:
        m,n=len(w1),len(w2); dp=list(range(n+1))
        for i in range(1,m+1):
            prev=dp[0]; dp[0]=i
            for j in range(1,n+1):
                temp=dp[j]
                if w1[i-1]==w2[j-1]: dp[j]=prev
                else: dp[j]=1+min(prev,dp[j],dp[j-1])
                prev=temp
        return dp[n]
