import java.util.HashMap;
import java.util.Map;

class Solution {
    // ============ MEMOIZATION (TOP-DOWN) ============
    public int canPartitionMemo(int nums) {
        total = sum(nums);
        if (total % 2 != 0) {
            return false;
        target = total // 2;
        n = len(nums);
        Map<Integer = new HashMap<>();;
    }
    // ============ TABULATION (BOTTOM-UP) ============
    public int canPartitionTab(int nums) {
        total = sum(nums);
        if (total % 2 != 0) {
            return false;
        target = total // 2;
        n = len(nums);
        dp = [[false] * (target + 1) for _ in range(n + 1)];
        for i in range(n + 1)) {
            dp[i][0] = true;
        for i in range(1, n + 1)) {
            for j in range(1, target + 1)) {
                if (nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
                else) {
                    dp[i][j] = dp[i-1][j];
        return dp[n][target];
    }
    public int canPartition(int nums) {
        total = sum(nums);
        if (total % 2 != 0) {
            return false;
        target = total // 2;
        dp = [false] * (target + 1);
        dp[0] = true;
        for num in nums) {
            for j in range(target, num - 1, -1)) {
                dp[j] = dp[j] || dp[j - num];
        return dp[target];
    }
}
