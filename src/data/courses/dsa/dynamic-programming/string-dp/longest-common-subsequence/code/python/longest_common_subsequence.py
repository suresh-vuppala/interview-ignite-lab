class Solution:
    # Memoization (Top-Down)
    def longestCommonSubsequence(self, text1, text2):
        m, n = len(text1), len(text2)
        memo = {}
        
        def dp(i, j):
            if i == m or j == n:
                return 0
            if (i, j) in memo:
                return memo[(i, j)]
            
            if text1[i] == text2[j]:
                memo[(i, j)] = 1 + dp(i+1, j+1)
            else:
                memo[(i, j)] = max(dp(i+1, j), dp(i, j+1))
            
            return memo[(i, j)]
        
        return dp(0, 0)
    
    # Tabulation (Bottom-Up)
    def longestCommonSubsequenceTabulation(self, text1, text2):
        m, n = len(text1), len(text2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if text1[i-1] == text2[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
        return dp[m][n]
    
    # Space Optimized
    def longestCommonSubsequenceOptimized(self, text1, text2):
        m, n = len(text1), len(text2)
        if m < n:
            text1, text2 = text2, text1
            m, n = n, m
        
        prev = [0] * (n + 1)
        
        for i in range(1, m + 1):
            curr = [0] * (n + 1)
            for j in range(1, n + 1):
                if text1[i-1] == text2[j-1]:
                    curr[j] = 1 + prev[j-1]
                else:
                    curr[j] = max(prev[j], curr[j-1])
            prev = curr
        
        return prev[n]