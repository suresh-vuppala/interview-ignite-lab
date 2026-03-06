class Solution:
    # ============ MEMOIZATION (TOP-DOWN) ============
    def climbStairsMemo(self, n):
        memo = {}
        def dp(i):
            if i <= 1:
                return 1
            if i in memo:
                return memo[i]
            memo[i] = dp(i-1) + dp(i-2)
            return memo[i]
        return dp(n)
    
    # ============ TABULATION (BOTTOM-UP) ============
    def climbStairsTab(self, n):
        if n <= 1:
            return 1
        dp = [0] * (n + 1)
        dp[0], dp[1] = 1, 1
        for i in range(2, n + 1):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n]
    
    # ============ SPACE OPTIMIZED ============
    def climbStairs(self, n):
        if n <= 1:
            return 1
        prev2, prev1 = 1, 1
        for i in range(2, n + 1):
            curr = prev1 + prev2
            prev2, prev1 = prev1, curr
        return prev1