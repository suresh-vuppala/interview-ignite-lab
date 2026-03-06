class Solution:
    # ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    # Time: O(2^(M+N)) | Space: O(M+N)
    def uniquePathsRecursive(self, obstacleGrid):
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        
        def solve(i, j):
            # Out of bounds or obstacle
            if i < 0 or j < 0 or obstacleGrid[i][j] == 1:
                return 0
            # Reached start
            if i == 0 and j == 0:
                return 1
            # Sum paths from top and left
            return solve(i-1, j) + solve(i, j-1)
        
        return solve(m-1, n-1)
    
    # ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    # Time: O(M×N) | Space: O(M×N)
    def uniquePathsMemo(self, obstacleGrid):
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        memo = {}
        
        def solve(i, j):
            if i < 0 or j < 0 or obstacleGrid[i][j] == 1:
                return 0
            if i == 0 and j == 0:
                return 1
            # Return cached result
            if (i, j) in memo:
                return memo[(i, j)]
            # Compute and cache
            memo[(i, j)] = solve(i-1, j) + solve(i, j-1)
            return memo[(i, j)]
        
        return solve(m-1, n-1)
    
    # ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    # Time: O(M×N) | Space: O(M×N)
    def uniquePathsTab(self, obstacleGrid):
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        if obstacleGrid[0][0] == 1:
            return 0
        
        dp = [[0] * n for _ in range(m)]
        dp[0][0] = 1
        
        for i in range(m):
            for j in range(n):
                if obstacleGrid[i][j] == 1:
                    dp[i][j] = 0
                elif i > 0 or j > 0:
                    above = dp[i-1][j] if i > 0 else 0
                    left = dp[i][j-1] if j > 0 else 0
                    dp[i][j] = above + left
        
        return dp[m-1][n-1]
    
    # ==================== SOLUTION 4: SPACE OPTIMIZED (TWO ROWS) ====================
    # Time: O(M×N) | Space: O(N)
    def uniquePathsTwoRows(self, obstacleGrid):
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        if obstacleGrid[0][0] == 1:
            return 0
        
        prev = [0] * n
        prev[0] = 1
        
        for i in range(m):
            curr = [0] * n
            for j in range(n):
                if obstacleGrid[i][j] == 1:
                    curr[j] = 0
                elif i == 0 and j == 0:
                    curr[j] = 1
                else:
                    above = prev[j] if i > 0 else 0
                    left = curr[j-1] if j > 0 else 0
                    curr[j] = above + left
            prev = curr
        
        return prev[n-1]
    
    # ==================== SOLUTION 5: SPACE OPTIMIZED (ONE ROW) - OPTIMAL ====================
    # Time: O(M×N) | Space: O(N)
    def uniquePathsWithObstacles(self, obstacleGrid):
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        if obstacleGrid[0][0] == 1:
            return 0
        
        dp = [0] * n
        dp[0] = 1
        
        for i in range(m):
            for j in range(n):
                if obstacleGrid[i][j] == 1:
                    dp[j] = 0
                elif j > 0:
                    # dp[j] has value from previous row (above)
                    # dp[j-1] has updated value from current row (left)
                    dp[j] += dp[j-1]
        
        return dp[n-1]
