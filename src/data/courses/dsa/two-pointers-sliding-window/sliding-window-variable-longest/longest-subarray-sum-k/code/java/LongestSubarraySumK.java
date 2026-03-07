// Time: O(N³), Space: O(1)
class LongestSubarraySumK {
    public int longestSubarrayBruteForce(int[] nums, int k) {
        int n = nums.length, maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int total = 0;
                for (int p = i; p <= j; p++) total += nums[p];
                if (total <= k) maxLen = Math.max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N²), Space: O(1)
    public int longestSubarrayBruteOptimized(int[] nums, int k) {
        int n = nums.length, maxLen = 0;
        for (int i = 0; i < n; i++) {
            int total = 0;
            for (int j = i; j < n; j++) {
                total += nums[j];
                if (total <= k) maxLen = Math.max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N²), Space: O(1)
    public int longestSubarrayTwoPointerShrink(int[] nums, int k) {
        int n = nums.length, maxLen = 0;
        for (int i = 0; i < n; i++) {
            int total = 0, j = i;
            while (j < n) {
                total += nums[j];
                if (total <= k) {
                    maxLen = Math.max(maxLen, j - i + 1);
                    j++;
                } else break;
            }
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N), Space: O(1)
    public int longestSubarraySlidingWindow(int[] nums, int k) {
        int left = 0, total = 0, maxLen = 0;
        for (int right = 0; right < nums.length; right++) {
            total += nums[right];
            while (total > k) {
                total -= nums[left];
                left++;
            }
            maxLen = Math.max(maxLen, right - left + 1);
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N), Space: O(1)
    public int longestSubarraySlidingWindowOptimized(int[] nums, int k) {
        int left = 0, total = 0, maxLen = 0;
        for (int right = 0; right < nums.length; right++) {
            total += nums[right];
            while (total > k) total -= nums[left++];
            maxLen = Math.max(maxLen, right - left + 1);
        }
        return maxLen;
    }
}
