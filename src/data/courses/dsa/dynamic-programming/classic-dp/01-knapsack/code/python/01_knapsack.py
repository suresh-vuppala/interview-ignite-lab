class Solution:
    # Memoization (Top-Down)
    def knapsack(self, weights, values, W):
        n = len(weights)
        memo = {}
        
        def dp(i, w):
            if i == 0 or w == 0:
                return 0
            if (i, w) in memo:
                return memo[(i, w)]
            
            if weights[i-1] <= w:
                memo[(i, w)] = max(
                    values[i-1] + dp(i-1, w - weights[i-1]),
                    dp(i-1, w)
                )
            else:
                memo[(i, w)] = dp(i-1, w)
            
            return memo[(i, w)]
        
        return dp(n, W)
    
    # Tabulation (Bottom-Up)
    def knapsackTabulation(self, weights, values, W):
        n = len(weights)
        dp = [[0] * (W + 1) for _ in range(n + 1)]
        
        for i in range(1, n + 1):
            for w in range(1, W + 1):
                if weights[i-1] <= w:
                    dp[i][w] = max(
                        values[i-1] + dp[i-1][w - weights[i-1]],
                        dp[i-1][w]
                    )
                else:
                    dp[i][w] = dp[i-1][w]
        
        return dp[n][W]
    
    # Space Optimized
    def knapsackOptimized(self, weights, values, W):
        n = len(weights)
        dp = [0] * (W + 1)
        
        for i in range(n):
            for w in range(W, weights[i] - 1, -1):
                dp[w] = max(dp[w], values[i] + dp[w - weights[i]])
        
        return dp[W]