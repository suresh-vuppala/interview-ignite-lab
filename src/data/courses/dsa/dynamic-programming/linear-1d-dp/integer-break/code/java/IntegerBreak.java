import java.util.HashMap;
import java.util.Map;

class Solution {
    // ============ MEMOIZATION (TOP-DOWN) ============
    public int integerBreakMemo(int n) {
        Map<Integer = new HashMap<>();;
    }
    // ============ TABULATION (BOTTOM-UP) ============
    public int integerBreak(int n) {
        int[] dp = new int[n + 1];
        dp[1] = 1;
        for i in range(2, n + 1)) {
            for j in range(1, i)) {
                dp[i] = max(dp[i], j * (i - j), j * dp[i - j]);
        return dp[n];
    }
    public int integerBreakOptimized(int n) {
        if (n <= 3) {
            return n - 1;
        product = 1;
        while n > 4) {
            product *= 3;
            n -= 3;
        return product * n;
    }
}
