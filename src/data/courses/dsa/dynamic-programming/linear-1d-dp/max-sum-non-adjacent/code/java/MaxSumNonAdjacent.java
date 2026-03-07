import java.util.HashMap;
import java.util.Map;

class Solution {
    // ============ MEMOIZATION (TOP-DOWN) ============
    public int maxSumNonAdjacentMemo(int arr) {
        n = len(arr);
        if (n == 0) {
            return 0;
        Map<Integer = new HashMap<>();;
    }
    // ============ TABULATION (BOTTOM-UP) ============
    public int maxSumNonAdjacentTab(int arr) {
        n = len(arr);
        if (n == 0) {
            return 0;
        if (n == 1) {
            return arr[0];
        dp = [0] * n;
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        for i in range(2, n)) {
            dp[i] = max(arr[i] + dp[i-2], dp[i-1]);
        return dp[n-1];
    }
    public int maxSumNonAdjacent(int arr) {
        if (!arr) {
            return 0;
        if (len(arr) == 1) {
            return arr[0];
        prev2, prev1 = arr[0], max(arr[0], arr[1]);
        for i in range(2, len(arr))) {
            curr = max(arr[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        return prev1;
    }
}
