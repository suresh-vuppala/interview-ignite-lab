import java.util.HashMap;
import java.util.Map;

class Solution {
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(4^N) | Space: O(N)
    public int cherryPickupRecursive(int[][] grid) {
        return Math.max(0, solve(grid, 0, 0, 0));
    }
    
    private int solve(int[][] grid, int r1, int c1, int r2) {
        int n = grid.length;
        int c2 = r1 + c1 - r2;
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return Integer.MIN_VALUE;
        }
        if (r1 == n-1 && c1 == n-1) return grid[r1][c1];
        int cherries = grid[r1][c1];
        if (r1 != r2) cherries += grid[r2][c2];
        cherries += Math.max(Math.max(solve(grid, r1+1, c1, r2+1), solve(grid, r1, c1+1, r2+1)),
                            Math.max(solve(grid, r1+1, c1, r2), solve(grid, r1, c1+1, r2)));
        return cherries;
    }
    
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(N³) | Space: O(N³)
    public int cherryPickupMemo(int[][] grid) {
        Map<String, Integer> memo = new HashMap<>();
        return Math.max(0, solveMemo(grid, 0, 0, 0, memo));
    }
    
    private int solveMemo(int[][] grid, int r1, int c1, int r2, Map<String, Integer> memo) {
        int n = grid.length;
        int c2 = r1 + c1 - r2;
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return Integer.MIN_VALUE;
        }
        if (r1 == n-1 && c1 == n-1) return grid[r1][c1];
        String key = r1 + "," + c1 + "," + r2;
        if (memo.containsKey(key)) return memo.get(key);
        int cherries = grid[r1][c1];
        if (r1 != r2) cherries += grid[r2][c2];
        cherries += Math.max(Math.max(solveMemo(grid, r1+1, c1, r2+1, memo), solveMemo(grid, r1, c1+1, r2+1, memo)),
                            Math.max(solveMemo(grid, r1+1, c1, r2, memo), solveMemo(grid, r1, c1+1, r2, memo)));
        memo.put(key, cherries);
        return cherries;
    }
    
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(N³) | Space: O(N³)
    public int cherryPickup(int[][] grid) {
        int n = grid.length;
        int[][][] dp = new int[n][n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    dp[i][j][k] = Integer.MIN_VALUE;
                }
            }
        }
        dp[0][0][0] = grid[0][0];
        for (int r1 = 0; r1 < n; r1++) {
            for (int c1 = 0; c1 < n; c1++) {
                for (int r2 = 0; r2 < n; r2++) {
                    int c2 = r1 + c1 - r2;
                    if (c2 < 0 || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) continue;
                    int cherries = grid[r1][c1];
                    if (r1 != r2) cherries += grid[r2][c2];
                    int[][] prev = {{r1-1, c1}, {r1, c1-1}};
                    for (int[] p1 : prev) {
                        for (int pr2 : new int[]{r2-1, r2}) {
                            if (p1[0] >= 0 && p1[1] >= 0 && pr2 >= 0) {
                                dp[r1][c1][r2] = Math.max(dp[r1][c1][r2], dp[p1[0]][p1[1]][pr2] + cherries);
                            }
                        }
                    }
                }
            }
        }
        return Math.max(0, dp[n-1][n-1][n-1]);
    }
}
