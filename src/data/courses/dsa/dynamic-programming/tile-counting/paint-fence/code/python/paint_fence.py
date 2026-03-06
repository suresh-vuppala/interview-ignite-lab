class Solution:
    # ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    # Time: O(2^n) | Space: O(n)
    def paintFenceRecursive(self, n, k):
        if n == 1: return k
        if n == 2: return k * k
        return (k - 1) * (self.paintFenceRecursive(n-1, k) + self.paintFenceRecursive(n-2, k))
    
    # ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    # Time: O(n) | Space: O(n)
    def paintFenceMemo(self, n, k):
        memo = {}
        def solve(i):
            if i == 1: return k
            if i == 2: return k * k
            if i in memo: return memo[i]
            memo[i] = (k - 1) * (solve(i-1) + solve(i-2))
            return memo[i]
        return solve(n)
    
    # ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    # Time: O(n) | Space: O(n)
    def paintFenceTab(self, n, k):
        if n == 1: return k
        if n == 2: return k * k
        dp = [0] * (n + 1)
        dp[1], dp[2] = k, k * k
        for i in range(3, n + 1):
            dp[i] = (k - 1) * (dp[i-1] + dp[i-2])
        return dp[n]
    
    # ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    # Time: O(n) | Space: O(1)
    def paintFence(self, n, k):
        if n == 1: return k
        if n == 2: return k * k
        prev2, prev1 = k, k * k
        for i in range(3, n + 1):
            curr = (k - 1) * (prev1 + prev2)
            prev2, prev1 = prev1, curr
        return prev1
