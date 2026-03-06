class Solution:
    # ============ MEMOIZATION (TOP-DOWN) ============
    def minCostClimbingStairsMemo(self, cost):
        n = len(cost)
        memo = {}
        
        def dp(i):
            if i >= n:
                return 0
            if i in memo:
                return memo[i]
            memo[i] = cost[i] + min(dp(i+1), dp(i+2))
            return memo[i]
        
        return min(dp(0), dp(1))
    
    # ============ TABULATION (BOTTOM-UP) ============
    def minCostClimbingStairs(self, cost):
        n = len(cost)
        dp = [0] * (n + 1)
        
        for i in range(2, n + 1):
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2])
        
        return dp[n]
    
    # ============ SPACE OPTIMIZED ============
    def minCostClimbingStairsOptimized(self, cost):
        prev2, prev1 = 0, 0
        
        for i in range(2, len(cost) + 1):
            curr = min(prev1 + cost[i-1], prev2 + cost[i-2])
            prev2, prev1 = prev1, curr
        
        return prev1
