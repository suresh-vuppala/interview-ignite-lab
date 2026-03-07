class Solution:
    # ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    # Time: O(2^(M+N)) | Space: O(M+N)
    def minPathSumRecursive(self, grid):
        m, n = len(grid), len(grid[0])
        def solve(i, j):
            if i == 0 and j == 0: return grid[0][0]
            if i < 0 or j < 0: return float('inf')
            return grid[i][j] + min(solve(i-1, j), solve(i, j-1))
        return solve(m-1, n-1)
    
    # ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    # Time: O(M×N) | Space: O(M×N)
    def minPathSumMemo(self, grid):
        m, n = len(grid), len(grid[0])
        memo = {}
        def solve(i, j):
            if i == 0 and j == 0: return grid[0][0]
            if i < 0 or j < 0: return float('inf')
            if (i, j) in memo: return memo[(i, j)]
            memo[(i, j)] = grid[i][j] + min(solve(i-1, j), solve(i, j-1))
            return memo[(i, j)]
        return solve(m-1, n-1)
    
    # ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    # Time: O(M×N) | Space: O(M×N)
    def minPathSumTab(self, grid):
        m, n = len(grid), len(grid[0])
        dp = [[0] * n for _ in range(m)]
        dp[0][0] = grid[0][0]
        for j in range(1, n):
            dp[0][j] = dp[0][j-1] + grid[0][j]
        for i in range(1, m):
            dp[i][0] = dp[i-1][0] + grid[i][0]
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
        return dp[m-1][n-1]
    
    # ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    # Time: O(M×N) | Space: O(N)
    def minPathSum(self, grid):
        m, n = len(grid), len(grid[0])
        dp = [0] * n
        dp[0] = grid[0][0]
        for j in range(1, n):
            dp[j] = dp[j-1] + grid[0][j]
        for i in range(1, m):
            dp[0] += grid[i][0]
            for j in range(1, n):
                dp[j] = grid[i][j] + min(dp[j], dp[j-1])
        return dp[n-1]
