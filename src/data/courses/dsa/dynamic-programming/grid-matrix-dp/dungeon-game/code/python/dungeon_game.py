class Solution:
    # ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    # Time: O(2^(M+N)) | Space: O(M+N)
    def calculateMinimumHPRecursive(self, dungeon):
        m, n = len(dungeon), len(dungeon[0])
        def solve(i, j):
            if i == m-1 and j == n-1:
                return max(1, 1 - dungeon[i][j])
            if i >= m or j >= n: return float('inf')
            right = solve(i, j+1)
            down = solve(i+1, j)
            min_hp = min(right, down) - dungeon[i][j]
            return max(1, min_hp)
        return solve(0, 0)
    
    # ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    # Time: O(M×N) | Space: O(M×N)
    def calculateMinimumHPMemo(self, dungeon):
        m, n = len(dungeon), len(dungeon[0])
        memo = {}
        def solve(i, j):
            if i == m-1 and j == n-1:
                return max(1, 1 - dungeon[i][j])
            if i >= m or j >= n: return float('inf')
            if (i, j) in memo: return memo[(i, j)]
            right = solve(i, j+1)
            down = solve(i+1, j)
            min_hp = min(right, down) - dungeon[i][j]
            memo[(i, j)] = max(1, min_hp)
            return memo[(i, j)]
        return solve(0, 0)
    
    # ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    # Time: O(M×N) | Space: O(M×N)
    def calculateMinimumHPTab(self, dungeon):
        m, n = len(dungeon), len(dungeon[0])
        dp = [[float('inf')] * (n+1) for _ in range(m+1)]
        dp[m][n-1] = dp[m-1][n] = 1
        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                min_hp = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]
                dp[i][j] = max(1, min_hp)
        return dp[0][0]
    
    # ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    # Time: O(M×N) | Space: O(N)
    def calculateMinimumHP(self, dungeon):
        m, n = len(dungeon), len(dungeon[0])
        dp = [float('inf')] * (n+1)
        dp[n-1] = 1
        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                min_hp = min(dp[j], dp[j+1]) - dungeon[i][j]
                dp[j] = max(1, min_hp)
        return dp[0]
