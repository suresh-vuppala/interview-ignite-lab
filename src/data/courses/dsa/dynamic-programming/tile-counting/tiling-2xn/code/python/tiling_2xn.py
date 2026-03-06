class Solution:
    # ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    # Time: O(2^n) | Space: O(n)
    def tilingRecursive(self, n):
        if n <= 1:
            return 1
        return self.tilingRecursive(n-1) + self.tilingRecursive(n-2)
    
    # ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    # Time: O(n) | Space: O(n)
    def tilingMemo(self, n):
        memo = {}
        def solve(i):
            if i <= 1:
                return 1
            if i in memo:
                return memo[i]
            memo[i] = solve(i-1) + solve(i-2)
            return memo[i]
        return solve(n)
    
    # ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    # Time: O(n) | Space: O(n)
    def tilingTab(self, n):
        if n <= 1:
            return 1
        dp = [0] * (n + 1)
        dp[0], dp[1] = 1, 1
        for i in range(2, n + 1):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n]
    
    # ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    # Time: O(n) | Space: O(1)
    def tiling2xN(self, n):
        if n <= 1:
            return 1
        prev2, prev1 = 1, 1
        for i in range(2, n + 1):
            curr = prev1 + prev2
            prev2, prev1 = prev1, curr
        return prev1
