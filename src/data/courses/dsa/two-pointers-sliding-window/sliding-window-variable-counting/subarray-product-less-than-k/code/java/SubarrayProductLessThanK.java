// ============================================================
// Subarray Product Less Than K
// ============================================================

// ============================================================
// Solution 1: Brute Force
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            int prod = 1;
            for (int j = i; j < nums.length; j++) {
                prod *= nums[j];
                if (prod >= k) break;
                count++;
            }
        }
        return count;
    }
}

// ============================================================
// Solution 2: Sliding Window (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k <= 1) return 0;
        int prod = 1, left = 0, count = 0;
        for (int right = 0; right < nums.length; right++) {
            prod *= nums[right];
            while (prod >= k) prod /= nums[left++];
            count += right - left + 1;
        }
        return count;
    }
}
