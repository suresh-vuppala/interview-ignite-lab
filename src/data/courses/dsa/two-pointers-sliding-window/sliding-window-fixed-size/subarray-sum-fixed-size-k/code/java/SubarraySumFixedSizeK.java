// ============================================================
// Subarray Sum — Fixed Size K
// ============================================================

// ============================================================
// Solution 1: Brute Force — Recompute Each Window
// Time: O(N×K) | Space: O(1)
// ============================================================
class Solution1 {
    public boolean hasSubarraySum(int[] nums, int k, int target) {
        for (int i = 0; i <= nums.length - k; i++) {
            int sum = 0;
            for (int j = i; j < i + k; j++) sum += nums[j];
            if (sum == target) return true;
        }
        return false;
    }
}

// ============================================================
// Solution 2: Sliding Window — Running Sum (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
    public boolean hasSubarraySum(int[] nums, int k, int target) {
        int sum = 0;
        for (int i = 0; i < k; i++) sum += nums[i];
        if (sum == target) return true;

        for (int i = k; i < nums.length; i++) {
            sum += nums[i] - nums[i - k];
            if (sum == target) return true;
        }

        return false;
    }
}
