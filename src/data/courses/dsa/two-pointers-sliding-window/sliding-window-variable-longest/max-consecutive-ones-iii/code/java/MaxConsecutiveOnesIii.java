// ============================================================
// Max Consecutive Ones III
// ============================================================

// ============================================================
// Solution 1: Brute Force
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
    public int longestOnes(int[] nums, int k) {
        int max = 0;
        for (int i = 0; i < nums.length; i++) {
            int zeros = 0;
            for (int j = i; j < nums.length; j++) {
                if (nums[j] == 0) zeros++;
                if (zeros > k) break;
                max = Math.max(max, j - i + 1);
            }
        }
        return max;
    }
}

// ============================================================
// Solution 2: Sliding Window (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
    public int longestOnes(int[] nums, int k) {
        int left = 0, zeros = 0, max = 0;
        for (int right = 0; right < nums.length; right++) {
            if (nums[right] == 0) zeros++;
            while (zeros > k) { if (nums[left] == 0) zeros--; left++; }
            max = Math.max(max, right - left + 1);
        }
        return max;
    }
}
