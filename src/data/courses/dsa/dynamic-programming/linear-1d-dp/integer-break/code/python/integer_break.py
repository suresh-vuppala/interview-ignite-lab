class Solution:
    # ============ MEMOIZATION (TOP-DOWN) ============
    def integerBreakMemo(self, n):
        memo = {}
        
        def dp(num):
            if num == 1:
                return 1
            if num in memo:
                return memo[num]
            
            max_prod = 0
            for j in range(1, num):
                max_prod = max(max_prod, j * (num - j), j * dp(num - j))
            
            memo[num] = max_prod
            return max_prod
        
        return dp(n)
    
    # ============ TABULATION (BOTTOM-UP) ============
    def integerBreak(self, n):
        dp = [0] * (n + 1)
        dp[1] = 1
        
        for i in range(2, n + 1):
            for j in range(1, i):
                dp[i] = max(dp[i], j * (i - j), j * dp[i - j])
        
        return dp[n]
    
    # ============ MATH OPTIMIZATION ============
    def integerBreakOptimized(self, n):
        if n <= 3:
            return n - 1
        
        product = 1
        while n > 4:
            product *= 3
            n -= 3
        
        return product * n
