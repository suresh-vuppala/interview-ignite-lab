class Solution:
    def unboundedKnapsack(self, W, wt, val):
        dp = [0] * (W + 1)
        for i in range(len(wt)):
            for w in range(wt[i], W+1):  # Left to right = reuse
                dp[w] = max(dp[w], dp[w-wt[i]] + val[i])
        return dp[W]
