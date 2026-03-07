import java.util.HashMap;
import java.util.Map;

class Solution {
    // ============ MEMOIZATION (TOP-DOWN) ============
    public int robMemo(int nums) {
        n = len(nums);
        if (n == 0) {
            return 0;
        if (n == 1) {
            return nums[0];
        Map<Integer = new HashMap<>();;
    }
    // ============ TABULATION (BOTTOM-UP) ============
    public int robTab(int nums) {
        n = len(nums);
        if (n == 0) {
            return 0;
        if (n == 1) {
            return nums[0];
        dp = [0] * n;
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for i in range(2, n)) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        return dp[n-1];
    }
    public int rob(int nums) {
        if (!nums) {
            return 0;
        if (len(nums) == 1) {
            return nums[0];
        prev2, prev1 = nums[0], max(nums[0], nums[1]);
        for i in range(2, len(nums))) {
            curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        return prev1;
    }
}
