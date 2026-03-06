import java.util.HashMap;

class Solution {
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(2^(M+N)) | Space: O(M+N)
    public int uniquePathsRecursive(int[][] obstacleGrid) {
        int m = obstacleGrid.length, n = obstacleGrid[0].length;
        return solveRecursive(m-1, n-1, obstacleGrid);
    }
    
    private int solveRecursive(int i, int j, int[][] grid) {
        // Out of bounds or obstacle
        if (i < 0 || j < 0 || grid[i][j] == 1) return 0;
        // Reached start
        if (i == 0 && j == 0) return 1;
        // Sum paths from top and left
        return solveRecursive(i-1, j, grid) + solveRecursive(i, j-1, grid);
    }
    
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(M×N) | Space: O(M×N)
    public int uniquePathsMemo(int[][] obstacleGrid) {
        int m = obstacleGrid.length, n = obstacleGrid[0].length;
        HashMap<String, Integer> memo = new HashMap<>();
        return solveMemo(m-1, n-1, obstacleGrid, memo);
    }
    
    private int solveMemo(int i, int j, int[][] grid, HashMap<String, Integer> memo) {
        if (i < 0 || j < 0 || grid[i][j] == 1) return 0;
        if (i == 0 && j == 0) return 1;
        
        String key = i + "," + j;
        // Return cached result
        if (memo.containsKey(key)) return memo.get(key);
        
        // Compute and cache
        int result = solveMemo(i-1, j, grid, memo) + solveMemo(i, j-1, grid, memo);
        memo.put(key, result);
        return result;
    }
    
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(M×N) | Space: O(M×N)
    public int uniquePathsTab(int[][] obstacleGrid) {
        int m = obstacleGrid.length, n = obstacleGrid[0].length;
        if (obstacleGrid[0][0] == 1) return 0;
        
        int[][] dp = new int[m][n];
        dp[0][0] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else if (i > 0 || j > 0) {
                    int above = (i > 0) ? dp[i-1][j] : 0;
                    int left = (j > 0) ? dp[i][j-1] : 0;
                    dp[i][j] = above + left;
                }
            }
        }
        
        return dp[m-1][n-1];
    }
    
    // ==================== SOLUTION 4: SPACE OPTIMIZED (TWO ROWS) ====================
    // Time: O(M×N) | Space: O(N)
    public int uniquePathsTwoRows(int[][] obstacleGrid) {
        int m = obstacleGrid.length, n = obstacleGrid[0].length;
        if (obstacleGrid[0][0] == 1) return 0;
        
        int[] prev = new int[n];
        prev[0] = 1;
        
        for (int i = 0; i < m; i++) {
            int[] curr = new int[n];
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    curr[j] = 0;
                } else if (i == 0 && j == 0) {
                    curr[j] = 1;
                } else {
                    int above = (i > 0) ? prev[j] : 0;
                    int left = (j > 0) ? curr[j-1] : 0;
                    curr[j] = above + left;
                }
            }
            prev = curr;
        }
        
        return prev[n-1];
    }
    
    // ==================== SOLUTION 5: SPACE OPTIMIZED (ONE ROW) - OPTIMAL ====================
    // Time: O(M×N) | Space: O(N)
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length, n = obstacleGrid[0].length;
        if (obstacleGrid[0][0] == 1) return 0;
        
        int[] dp = new int[n];
        dp[0] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else if (j > 0) {
                    // dp[j] has value from previous row (above)
                    // dp[j-1] has updated value from current row (left)
                    dp[j] += dp[j-1];
                }
            }
        }
        
        return dp[n-1];
    }
}
