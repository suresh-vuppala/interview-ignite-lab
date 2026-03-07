class Solution:
    # ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    # Time: O(3^(M+N)) | Space: O(M+N)
    def minDistanceRecursive(self, word1, word2):
        def solve(i, j):
            if i == 0: return j
            if j == 0: return i
            if word1[i-1] == word2[j-1]:
                return solve(i-1, j-1)
            return 1 + min(solve(i-1, j), solve(i, j-1), solve(i-1, j-1))
        return solve(len(word1), len(word2))
    
    # ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    # Time: O(M×N) | Space: O(M×N)
    def minDistanceMemo(self, word1, word2):
        memo = {}
        def solve(i, j):
            if i == 0: return j
            if j == 0: return i
            if (i, j) in memo: return memo[(i, j)]
            if word1[i-1] == word2[j-1]:
                memo[(i, j)] = solve(i-1, j-1)
            else:
                memo[(i, j)] = 1 + min(solve(i-1, j), solve(i, j-1), solve(i-1, j-1))
            return memo[(i, j)]
        return solve(len(word1), len(word2))
    
    # ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    # Time: O(M×N) | Space: O(M×N)
    def minDistanceTab(self, word1, word2):
        m, n = len(word1), len(word2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m + 1):
            dp[i][0] = i
        for j in range(n + 1):
            dp[0][j] = j
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
        return dp[m][n]
    
    # ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    # Time: O(M×N) | Space: O(N)
    def minDistance(self, word1, word2):
        m, n = len(word1), len(word2)
        prev = list(range(n + 1))
        for i in range(1, m + 1):
            curr = [i] + [0] * n
            for j in range(1, n + 1):
                if word1[i-1] == word2[j-1]:
                    curr[j] = prev[j-1]
                else:
                    curr[j] = 1 + min(prev[j], curr[j-1], prev[j-1])
            prev = curr
        return prev[n]
