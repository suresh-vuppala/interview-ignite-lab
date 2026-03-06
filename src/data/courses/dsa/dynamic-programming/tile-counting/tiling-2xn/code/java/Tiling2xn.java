import java.util.HashMap;
import java.util.Map;

class Solution {
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(2^n) | Space: O(n)
    public int tilingRecursive(int n) {
        if (n <= 1) return 1;
        return tilingRecursive(n-1) + tilingRecursive(n-2);
    }
    
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(n) | Space: O(n)
    public int tilingMemo(int n) {
        Map<Integer, Integer> memo = new HashMap<>();
        return solve(n, memo);
    }
    
    private int solve(int i, Map<Integer, Integer> memo) {
        if (i <= 1) return 1;
        if (memo.containsKey(i)) return memo.get(i);
        int result = solve(i-1, memo) + solve(i-2, memo);
        memo.put(i, result);
        return result;
    }
    
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(n) | Space: O(n)
    public int tilingTab(int n) {
        if (n <= 1) return 1;
        int[] dp = new int[n + 1];
        dp[0] = 1; dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    
    // ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    // Time: O(n) | Space: O(1)
    public int tiling2xN(int n) {
        if (n <= 1) return 1;
        int prev2 = 1, prev1 = 1;
        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
}
