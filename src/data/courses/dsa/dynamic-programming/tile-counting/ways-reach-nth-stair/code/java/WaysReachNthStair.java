import java.util.HashMap;
import java.util.Map;

class Solution {
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(3^n) | Space: O(n)
    public int waysRecursive(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;
        return waysRecursive(n-1) + waysRecursive(n-2) + waysRecursive(n-3);
    }
    
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(n) | Space: O(n)
    public int waysMemo(int n) {
        Map<Integer, Integer> memo = new HashMap<>();
        return solve(n, memo);
    }
    
    private int solve(int i, Map<Integer, Integer> memo) {
        if (i == 0) return 1;
        if (i == 1) return 1;
        if (i == 2) return 2;
        if (memo.containsKey(i)) return memo.get(i);
        int result = solve(i-1, memo) + solve(i-2, memo) + solve(i-3, memo);
        memo.put(i, result);
        return result;
    }
    
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(n) | Space: O(n)
    public int waysTab(int n) {
        if (n <= 1) return 1;
        if (n == 2) return 2;
        int[] dp = new int[n + 1];
        dp[0] = 1; dp[1] = 1; dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }
    
    // ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    // Time: O(n) | Space: O(1)
    public int waysToReachNthStair(int n) {
        if (n <= 1) return 1;
        if (n == 2) return 2;
        int prev3 = 1, prev2 = 1, prev1 = 2;
        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
}
