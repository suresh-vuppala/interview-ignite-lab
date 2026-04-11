// ============================================================
// Maximum Sum Subarray of Size K
// ============================================================

// ============================================================
// Solution 1: Brute Force
// Time: O(N×K) | Space: O(1)
// ============================================================
class Solution1 {
    public int maxSumSubarray(int[] nums, int k) {
        int max = Integer.MIN_VALUE;
        for (int i = 0; i <= nums.length - k; i++) {
            int sum = 0;
            for (int j = i; j < i + k; j++) sum += nums[j];
            max = Math.max(max, sum);
        }
        return max;
    }
}

// ============================================================
// Solution 2: Sliding Window — Running Max (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
    public int maxSumSubarray(int[] nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) sum += nums[i];
        int max = sum;
        for (int i = k; i < nums.length; i++) {
            sum += nums[i] - nums[i - k];
            max = Math.max(max, sum);
        }
        return max;
    }
}
