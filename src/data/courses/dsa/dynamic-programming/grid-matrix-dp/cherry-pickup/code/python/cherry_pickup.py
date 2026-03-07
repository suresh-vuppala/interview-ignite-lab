class Solution:
    # ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    # Time: O(4^N) | Space: O(N)
    def cherryPickupRecursive(self, grid):
        n = len(grid)
        def solve(r1, c1, r2):
            c2 = r1 + c1 - r2
            if r1 >= n or c1 >= n or r2 >= n or c2 >= n or grid[r1][c1] == -1 or grid[r2][c2] == -1:
                return float('-inf')
            if r1 == n-1 and c1 == n-1: return grid[r1][c1]
            cherries = grid[r1][c1]
            if r1 != r2: cherries += grid[r2][c2]
            cherries += max(solve(r1+1, c1, r2+1), solve(r1, c1+1, r2+1),
                           solve(r1+1, c1, r2), solve(r1, c1+1, r2))
            return cherries
        return max(0, solve(0, 0, 0))
    
    # ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    # Time: O(N³) | Space: O(N³)
    def cherryPickupMemo(self, grid):
        n = len(grid)
        memo = {}
        def solve(r1, c1, r2):
            c2 = r1 + c1 - r2
            if r1 >= n or c1 >= n or r2 >= n or c2 >= n or grid[r1][c1] == -1 or grid[r2][c2] == -1:
                return float('-inf')
            if r1 == n-1 and c1 == n-1: return grid[r1][c1]
            if (r1, c1, r2) in memo: return memo[(r1, c1, r2)]
            cherries = grid[r1][c1]
            if r1 != r2: cherries += grid[r2][c2]
            cherries += max(solve(r1+1, c1, r2+1), solve(r1, c1+1, r2+1),
                           solve(r1+1, c1, r2), solve(r1, c1+1, r2))
            memo[(r1, c1, r2)] = cherries
            return cherries
        return max(0, solve(0, 0, 0))
    
    # ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    # Time: O(N³) | Space: O(N³)
    def cherryPickup(self, grid):
        n = len(grid)
        dp = [[[float('-inf')] * n for _ in range(n)] for _ in range(n)]
        dp[0][0][0] = grid[0][0]
        for r1 in range(n):
            for c1 in range(n):
                for r2 in range(n):
                    c2 = r1 + c1 - r2
                    if c2 < 0 or c2 >= n or grid[r1][c1] == -1 or grid[r2][c2] == -1:
                        continue
                    cherries = grid[r1][c1]
                    if r1 != r2: cherries += grid[r2][c2]
                    for pr1, pc1, pr2 in [(r1-1, c1, r2-1), (r1, c1-1, r2-1), (r1-1, c1, r2), (r1, c1-1, r2)]:
                        if pr1 >= 0 and pc1 >= 0 and pr2 >= 0:
                            dp[r1][c1][r2] = max(dp[r1][c1][r2], dp[pr1][pc1][pr2] + cherries)
        return max(0, dp[n-1][n-1][n-1])
