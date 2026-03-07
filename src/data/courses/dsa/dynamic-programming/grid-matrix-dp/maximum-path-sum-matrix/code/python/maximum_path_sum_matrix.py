class Solution:
    # ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    # Time: O(3^M) | Space: O(M)
    def maxPathSumRecursive(self, matrix):
        m, n = len(matrix), len(matrix[0])
        def solve(i, j):
            if j < 0 or j >= n: return float('-inf')
            if i == 0: return matrix[0][j]
            return matrix[i][j] + max(solve(i-1, j-1), solve(i-1, j), solve(i-1, j+1))
        return max(solve(m-1, j) for j in range(n))
    
    # ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    # Time: O(M×N) | Space: O(M×N)
    def maxPathSumMemo(self, matrix):
        m, n = len(matrix), len(matrix[0])
        memo = {}
        def solve(i, j):
            if j < 0 or j >= n: return float('-inf')
            if i == 0: return matrix[0][j]
            if (i, j) in memo: return memo[(i, j)]
            memo[(i, j)] = matrix[i][j] + max(solve(i-1, j-1), solve(i-1, j), solve(i-1, j+1))
            return memo[(i, j)]
        return max(solve(m-1, j) for j in range(n))
    
    # ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    # Time: O(M×N) | Space: O(M×N)
    def maxPathSumTab(self, matrix):
        m, n = len(matrix), len(matrix[0])
        dp = [[0] * n for _ in range(m)]
        for j in range(n):
            dp[0][j] = matrix[0][j]
        for i in range(1, m):
            for j in range(n):
                up = dp[i-1][j]
                left_diag = dp[i-1][j-1] if j > 0 else float('-inf')
                right_diag = dp[i-1][j+1] if j < n-1 else float('-inf')
                dp[i][j] = matrix[i][j] + max(up, left_diag, right_diag)
        return max(dp[m-1])
    
    # ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    # Time: O(M×N) | Space: O(N)
    def maxPathSum(self, matrix):
        m, n = len(matrix), len(matrix[0])
        prev = matrix[0][:]
        for i in range(1, m):
            curr = [0] * n
            for j in range(n):
                up = prev[j]
                left_diag = prev[j-1] if j > 0 else float('-inf')
                right_diag = prev[j+1] if j < n-1 else float('-inf')
                curr[j] = matrix[i][j] + max(up, left_diag, right_diag)
            prev = curr
        return max(prev)
