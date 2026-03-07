import java.util.HashMap;
import java.util.Map;

class Solution {
    // ============ MEMOIZATION (TOP-DOWN) ============
    public int maxSubArrayMemo(int nums) {
        n = len(nums);
        Map<Integer = new HashMap<>();;
    }
    // ============ TABULATION (BOTTOM-UP) ============
    public int maxSubArrayTab(int nums) {
        n = len(nums);
        dp = [0] * n;
        dp[0] = nums[0];
        max_sum = dp[0];
        for i in range(1, n)) {
            dp[i] = max(nums[i], nums[i] + dp[i-1]);
            max_sum = max(max_sum, dp[i]);
        return max_sum;
    }
    public int maxSubArray(int nums) {
        max_ending_here = max_so_far = nums[0];
        for i in range(1, len(nums))) {
            max_ending_here = max(nums[i], max_ending_here + nums[i]);
            max_so_far = max(max_so_far, max_ending_here);
        return max_so_far;
    }
}
