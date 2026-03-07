import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(2^N) | Space: O(N)
    public int minimumTotalRecursive(List<List<Integer>> triangle) {
        return solve(triangle, 0, 0);
    }
    
    private int solve(List<List<Integer>> triangle, int i, int j) {
        if (i == triangle.size()) return 0;
        return triangle.get(i).get(j) + Math.min(solve(triangle, i+1, j), solve(triangle, i+1, j+1));
    }
    
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(N²) | Space: O(N²)
    public int minimumTotalMemo(List<List<Integer>> triangle) {
        Map<String, Integer> memo = new HashMap<>();
        return solveMemo(triangle, 0, 0, memo);
    }
    
    private int solveMemo(List<List<Integer>> triangle, int i, int j, Map<String, Integer> memo) {
        if (i == triangle.size()) return 0;
        String key = i + "," + j;
        if (memo.containsKey(key)) return memo.get(key);
        int result = triangle.get(i).get(j) + Math.min(solveMemo(triangle, i+1, j, memo), 
                                                        solveMemo(triangle, i+1, j+1, memo));
        memo.put(key, result);
        return result;
    }
    
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(N²) | Space: O(N²)
    public int minimumTotalTab(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[][] dp = new int[n][];
        for (int i = 0; i < n; i++) {
            dp[i] = new int[i+1];
        }
        dp[0][0] = triangle.get(0).get(0);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    dp[i][j] = dp[i-1][j] + triangle.get(i).get(j);
                } else if (j == i) {
                    dp[i][j] = dp[i-1][j-1] + triangle.get(i).get(j);
                } else {
                    dp[i][j] = triangle.get(i).get(j) + Math.min(dp[i-1][j-1], dp[i-1][j]);
                }
            }
        }
        int result = Integer.MAX_VALUE;
        for (int j = 0; j < n; j++) {
            result = Math.min(result, dp[n-1][j]);
        }
        return result;
    }
    
    // ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    // Time: O(N²) | Space: O(N)
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[] dp = new int[n];
        for (int j = 0; j < n; j++) {
            dp[j] = triangle.get(n-1).get(j);
        }
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle.get(i).get(j) + Math.min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
}
