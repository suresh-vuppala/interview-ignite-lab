import java.util.HashMap;
import java.util.Map;

class Solution {
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(2^(M+N)) | Space: O(M+N)
    public int calculateMinimumHPRecursive(int[][] dungeon) {
        return solve(dungeon, 0, 0);
    }
    
    private int solve(int[][] dungeon, int i, int j) {
        int m = dungeon.length, n = dungeon[0].length;
        if (i == m-1 && j == n-1) {
            return Math.max(1, 1 - dungeon[i][j]);
        }
        if (i >= m || j >= n) return Integer.MAX_VALUE;
        int right = solve(dungeon, i, j+1);
        int down = solve(dungeon, i+1, j);
        int minHP = Math.min(right, down) - dungeon[i][j];
        return Math.max(1, minHP);
    }
    
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(M×N) | Space: O(M×N)
    public int calculateMinimumHPMemo(int[][] dungeon) {
        Map<String, Integer> memo = new HashMap<>();
        return solveMemo(dungeon, 0, 0, memo);
    }
    
    private int solveMemo(int[][] dungeon, int i, int j, Map<String, Integer> memo) {
        int m = dungeon.length, n = dungeon[0].length;
        if (i == m-1 && j == n-1) {
            return Math.max(1, 1 - dungeon[i][j]);
        }
        if (i >= m || j >= n) return Integer.MAX_VALUE;
        String key = i + "," + j;
        if (memo.containsKey(key)) return memo.get(key);
        int right = solveMemo(dungeon, i, j+1, memo);
        int down = solveMemo(dungeon, i+1, j, memo);
        int minHP = Math.min(right, down) - dungeon[i][j];
        int result = Math.max(1, minHP);
        memo.put(key, result);
        return result;
    }
    
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(M×N) | Space: O(M×N)
    public int calculateMinimumHPTab(int[][] dungeon) {
        int m = dungeon.length, n = dungeon[0].length;
        int[][] dp = new int[m+1][n+1];
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        dp[m][n-1] = dp[m-1][n] = 1;
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                int minHP = Math.min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = Math.max(1, minHP);
            }
        }
        return dp[0][0];
    }
    
    // ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    // Time: O(M×N) | Space: O(N)
    public int calculateMinimumHP(int[][] dungeon) {
        int m = dungeon.length, n = dungeon[0].length;
        int[] dp = new int[n+1];
        for (int j = 0; j <= n; j++) {
            dp[j] = Integer.MAX_VALUE;
        }
        dp[n-1] = 1;
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                int minHP = Math.min(dp[j], dp[j+1]) - dungeon[i][j];
                dp[j] = Math.max(1, minHP);
            }
        }
        return dp[0];
    }
}
