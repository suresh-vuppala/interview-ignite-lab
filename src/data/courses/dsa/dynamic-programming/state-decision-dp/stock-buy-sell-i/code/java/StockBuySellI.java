import java.util.HashMap;
import java.util.Map;

class Solution {
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(2^N) | Space: O(N)
    public int maxProfitRecursive(int[] prices) {
        return solve(prices, 0, false);
    }
    
    private int solve(int[] prices, int i, boolean holding) {
        if (i == prices.length) return 0;
        if (holding) {
            int sell = prices[i] + solve(prices, i + 1, false);
            int hold = solve(prices, i + 1, true);
            return Math.max(sell, hold);
        } else {
            int buy = -prices[i] + solve(prices, i + 1, true);
            int skip = solve(prices, i + 1, false);
            return Math.max(buy, skip);
        }
    }
    
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(N) | Space: O(N)
    public int maxProfitMemo(int[] prices) {
        Map<String, Integer> memo = new HashMap<>();
        return solveMemo(prices, 0, false, memo);
    }
    
    private int solveMemo(int[] prices, int i, boolean holding, Map<String, Integer> memo) {
        if (i == prices.length) return 0;
        String key = i + "," + holding;
        if (memo.containsKey(key)) return memo.get(key);
        int result;
        if (holding) {
            int sell = prices[i] + solveMemo(prices, i + 1, false, memo);
            int hold = solveMemo(prices, i + 1, true, memo);
            result = Math.max(sell, hold);
        } else {
            int buy = -prices[i] + solveMemo(prices, i + 1, true, memo);
            int skip = solveMemo(prices, i + 1, false, memo);
            result = Math.max(buy, skip);
        }
        memo.put(key, result);
        return result;
    }
    
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(N) | Space: O(N)
    public int maxProfitTab(int[] prices) {
        int n = prices.length;
        int[][] dp = new int[n + 1][2];
        for (int i = n - 1; i >= 0; i--) {
            dp[i][0] = Math.max(-prices[i] + dp[i + 1][1], dp[i + 1][0]);
            dp[i][1] = Math.max(prices[i] + dp[i + 1][0], dp[i + 1][1]);
        }
        return dp[0][0];
    }
    
    // ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    // Time: O(N) | Space: O(1)
    public int maxProfit(int[] prices) {
        int minPrice = Integer.MAX_VALUE;
        int maxProfit = 0;
        for (int price : prices) {
            minPrice = Math.min(minPrice, price);
            maxProfit = Math.max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
}
