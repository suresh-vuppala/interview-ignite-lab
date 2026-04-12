class Solution:
    def rodCutting(self, price, n):
        dp = [0] * (n+1)
        for l in range(1, n+1):
            for i in range(1, l+1): dp[l] = max(dp[l], price[i-1] + dp[l-i])
        return dp[n]
