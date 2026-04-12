class Solution:
    def longestCommonSubstring(self, s1, s2) -> int:
        m,n,max_len=len(s1),len(s2),0; dp=[0]*(n+1)
        for i in range(1,m+1):
            ndp=[0]*(n+1)
            for j in range(1,n+1):
                ndp[j]=dp[j-1]+1 if s1[i-1]==s2[j-1] else 0
                max_len=max(max_len,ndp[j])
            dp=ndp
        return max_len
