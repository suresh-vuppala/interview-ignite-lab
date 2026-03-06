import java.util.HashMap;

class Solution {
    // ============ MEMOIZATION (TOP-DOWN) ============
    public int climbStairsMemo(int n) {
        HashMap<Integer, Integer> memo = new HashMap<>();
        return dpMemo(n, memo);
    }
    
    private int dpMemo(int n, HashMap<Integer, Integer> memo) {
        if (n <= 1) return 1;
        if (memo.containsKey(n)) return memo.get(n);
        int result = dpMemo(n-1, memo) + dpMemo(n-2, memo);
        memo.put(n, result);
        return result;
    }
    
    // ============ TABULATION (BOTTOM-UP) ============
    public int climbStairsTab(int n) {
        if (n <= 1) return 1;
        int[] dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    
    // ============ SPACE OPTIMIZED ============
    public int climbStairs(int n) {
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