import java.util.HashMap;
import java.util.Map;

class Solution {
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(2^n) | Space: O(n)
    public int paintFenceRecursive(int n, int k) {
        if (n == 1) return k;
        if (n == 2) return k * k;
        return (k - 1) * (paintFenceRecursive(n-1, k) + paintFenceRecursive(n-2, k));
    }
    
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(n) | Space: O(n)
    public int paintFenceMemo(int n, int k) {
        Map<Integer, Integer> memo = new HashMap<>();
        return solve(n, k, memo);
    }
    
    private int solve(int i, int k, Map<Integer, Integer> memo) {
        if (i == 1) return k;
        if (i == 2) return k * k;
        if (memo.containsKey(i)) return memo.get(i);
        int result = (k - 1) * (solve(i-1, k, memo) + solve(i-2, k, memo));
        memo.put(i, result);
        return result;
    }
    
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(n) | Space: O(n)
    public int paintFenceTab(int n, int k) {
        if (n == 1) return k;
        if (n == 2) return k * k;
        int[] dp = new int[n + 1];
        dp[1] = k; dp[2] = k * k;
        for (int i = 3; i <= n; i++) {
            dp[i] = (k - 1) * (dp[i-1] + dp[i-2]);
        }
        return dp[n];
    }
    
    // ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    // Time: O(n) | Space: O(1)
    public int paintFence(int n, int k) {
        if (n == 1) return k;
        if (n == 2) return k * k;
        int prev2 = k, prev1 = k * k;
        for (int i = 3; i <= n; i++) {
            int curr = (k - 1) * (prev1 + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
}
