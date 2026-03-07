import java.util.HashMap;
import java.util.Map;

class Solution {
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(3^M) | Space: O(M)
    public int maxPathSumRecursive(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int result = Integer.MIN_VALUE;
        for (int j = 0; j < n; j++) {
            result = Math.max(result, solve(matrix, m-1, j));
        }
        return result;
    }
    
    private int solve(int[][] matrix, int i, int j) {
        int n = matrix[0].length;
        if (j < 0 || j >= n) return Integer.MIN_VALUE;
        if (i == 0) return matrix[0][j];
        return matrix[i][j] + Math.max(Math.max(solve(matrix, i-1, j-1), solve(matrix, i-1, j)), 
                                       solve(matrix, i-1, j+1));
    }
    
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(M×N) | Space: O(M×N)
    public int maxPathSumMemo(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        Map<String, Integer> memo = new HashMap<>();
        int result = Integer.MIN_VALUE;
        for (int j = 0; j < n; j++) {
            result = Math.max(result, solveMemo(matrix, m-1, j, memo));
        }
        return result;
    }
    
    private int solveMemo(int[][] matrix, int i, int j, Map<String, Integer> memo) {
        int n = matrix[0].length;
        if (j < 0 || j >= n) return Integer.MIN_VALUE;
        if (i == 0) return matrix[0][j];
        String key = i + "," + j;
        if (memo.containsKey(key)) return memo.get(key);
        int result = matrix[i][j] + Math.max(Math.max(solveMemo(matrix, i-1, j-1, memo), 
                                                       solveMemo(matrix, i-1, j, memo)), 
                                             solveMemo(matrix, i-1, j+1, memo));
        memo.put(key, result);
        return result;
    }
    
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(M×N) | Space: O(M×N)
    public int maxPathSumTab(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[][] dp = new int[m][n];
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int up = dp[i-1][j];
                int leftDiag = (j > 0) ? dp[i-1][j-1] : Integer.MIN_VALUE;
                int rightDiag = (j < n-1) ? dp[i-1][j+1] : Integer.MIN_VALUE;
                dp[i][j] = matrix[i][j] + Math.max(Math.max(up, leftDiag), rightDiag);
            }
        }
        int result = Integer.MIN_VALUE;
        for (int j = 0; j < n; j++) {
            result = Math.max(result, dp[m-1][j]);
        }
        return result;
    }
    
    // ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    // Time: O(M×N) | Space: O(N)
    public int maxPathSum(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[] prev = new int[n];
        for (int j = 0; j < n; j++) {
            prev[j] = matrix[0][j];
        }
        for (int i = 1; i < m; i++) {
            int[] curr = new int[n];
            for (int j = 0; j < n; j++) {
                int up = prev[j];
                int leftDiag = (j > 0) ? prev[j-1] : Integer.MIN_VALUE;
                int rightDiag = (j < n-1) ? prev[j+1] : Integer.MIN_VALUE;
                curr[j] = matrix[i][j] + Math.max(Math.max(up, leftDiag), rightDiag);
            }
            prev = curr;
        }
        int result = Integer.MIN_VALUE;
        for (int j = 0; j < n; j++) {
            result = Math.max(result, prev[j]);
        }
        return result;
    }
}
