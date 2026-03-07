class Solution:
    # ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    # Time: O(2^N) | Space: O(N)
    def minimumTotalRecursive(self, triangle):
        def solve(i, j):
            if i == len(triangle): return 0
            return triangle[i][j] + min(solve(i+1, j), solve(i+1, j+1))
        return solve(0, 0)
    
    # ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    # Time: O(N²) | Space: O(N²)
    def minimumTotalMemo(self, triangle):
        memo = {}
        def solve(i, j):
            if i == len(triangle): return 0
            if (i, j) in memo: return memo[(i, j)]
            memo[(i, j)] = triangle[i][j] + min(solve(i+1, j), solve(i+1, j+1))
            return memo[(i, j)]
        return solve(0, 0)
    
    # ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    # Time: O(N²) | Space: O(N²)
    def minimumTotalTab(self, triangle):
        n = len(triangle)
        dp = [[0] * (i+1) for i in range(n)]
        dp[0][0] = triangle[0][0]
        for i in range(1, n):
            for j in range(i+1):
                if j == 0:
                    dp[i][j] = dp[i-1][j] + triangle[i][j]
                elif j == i:
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j]
                else:
                    dp[i][j] = triangle[i][j] + min(dp[i-1][j-1], dp[i-1][j])
        return min(dp[n-1])
    
    # ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    # Time: O(N²) | Space: O(N)
    def minimumTotal(self, triangle):
        n = len(triangle)
        dp = triangle[-1][:]
        for i in range(n-2, -1, -1):
            for j in range(i+1):
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1])
        return dp[0]
