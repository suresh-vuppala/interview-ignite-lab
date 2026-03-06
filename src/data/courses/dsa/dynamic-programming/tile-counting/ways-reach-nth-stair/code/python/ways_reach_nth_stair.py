class Solution:
    # ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    # Time: O(3^n) | Space: O(n)
    def waysRecursive(self, n):
        if n == 0: return 1
        if n == 1: return 1
        if n == 2: return 2
        return self.waysRecursive(n-1) + self.waysRecursive(n-2) + self.waysRecursive(n-3)
    
    # ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    # Time: O(n) | Space: O(n)
    def waysMemo(self, n):
        memo = {}
        def solve(i):
            if i == 0: return 1
            if i == 1: return 1
            if i == 2: return 2
            if i in memo: return memo[i]
            memo[i] = solve(i-1) + solve(i-2) + solve(i-3)
            return memo[i]
        return solve(n)
    
    # ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    # Time: O(n) | Space: O(n)
    def waysTab(self, n):
        if n <= 1: return 1
        if n == 2: return 2
        dp = [0] * (n + 1)
        dp[0], dp[1], dp[2] = 1, 1, 2
        for i in range(3, n + 1):
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
        return dp[n]
    
    # ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    # Time: O(n) | Space: O(1)
    def waysToReachNthStair(self, n):
        if n <= 1: return 1
        if n == 2: return 2
        prev3, prev2, prev1 = 1, 1, 2
        for i in range(3, n + 1):
            curr = prev1 + prev2 + prev3
            prev3, prev2, prev1 = prev2, prev1, curr
        return prev1
