// ============================================================
// Minimum Size Subarray Sum
// ============================================================

// ============================================================
// Solution 1: Brute Force
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
    public int minSubArrayLen(int target, int[] nums) {
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length; i++) {
            int sum = 0;
            for (int j = i; j < nums.length; j++) {
                sum += nums[j];
                if (sum >= target) { min = Math.min(min, j-i+1); break; }
            }
        }
        return min == Integer.MAX_VALUE ? 0 : min;
    }
}

// ============================================================
// Solution 2: Sliding Window (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
    public int minSubArrayLen(int target, int[] nums) {
        int left = 0, sum = 0, min = Integer.MAX_VALUE;
        for (int right = 0; right < nums.length; right++) {
            sum += nums[right];
            while (sum >= target) {
                min = Math.min(min, right - left + 1);
                sum -= nums[left++];
            }
        }
        return min == Integer.MAX_VALUE ? 0 : min;
    }
}
