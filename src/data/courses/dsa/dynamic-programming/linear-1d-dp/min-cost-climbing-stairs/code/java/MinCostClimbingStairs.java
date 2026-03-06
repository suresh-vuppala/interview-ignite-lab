import java.util.HashMap;

class Solution {
    // ============ MEMOIZATION (TOP-DOWN) ============
    public int minCostClimbingStairsMemo(int[] cost) {
        HashMap<Integer, Integer> memo = new HashMap<>();
        return Math.min(dpMemo(0, cost, memo), dpMemo(1, cost, memo));
    }
    
    private int dpMemo(int i, int[] cost, HashMap<Integer, Integer> memo) {
        if (i >= cost.length) return 0;
        if (memo.containsKey(i)) return memo.get(i);
        int result = cost[i] + Math.min(dpMemo(i+1, cost, memo), dpMemo(i+2, cost, memo));
        memo.put(i, result);
        return result;
    }
    
    // ============ TABULATION (BOTTOM-UP) ============
    public int minCostClimbingStairsTab(int[] cost) {
        int n = cost.length;
        int[] dp = new int[n + 1];
        
        for (int i = 2; i <= n; i++) {
            dp[i] = Math.min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[n];
    }
    
    // ============ SPACE OPTIMIZED ============
    public int minCostClimbingStairs(int[] cost) {
        int prev2 = 0, prev1 = 0;
        
        for (int i = 2; i <= cost.length; i++) {
            int curr = Math.min(prev1 + cost[i-1], prev2 + cost[i-2]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
}
