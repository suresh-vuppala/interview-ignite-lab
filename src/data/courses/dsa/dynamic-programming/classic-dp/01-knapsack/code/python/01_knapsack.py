class Solution:
    def knapsack(self, W, wt, val):
        dp = [0] * (W + 1)
        for i in range(len(wt)):
            for w in range(W, wt[i]-1, -1):  # Right to left!
                dp[w] = max(dp[w], dp[w-wt[i]] + val[i])
        return dp[W]
