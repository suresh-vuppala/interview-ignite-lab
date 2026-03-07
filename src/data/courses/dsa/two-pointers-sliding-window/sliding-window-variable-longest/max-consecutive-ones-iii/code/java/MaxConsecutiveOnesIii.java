// Time: O(N³), Space: O(1)
class MaxConsecutiveOnesIii {
    public int longestOnesBruteForce(int[] nums, int k) {
        int n = nums.length, maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int zeros = 0;
                for (int p = i; p <= j; p++) if (nums[p] == 0) zeros++;
                if (zeros <= k) maxLen = Math.max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N²), Space: O(1)
    public int longestOnesBruteOptimized(int[] nums, int k) {
        int n = nums.length, maxLen = 0;
        for (int i = 0; i < n; i++) {
            int zeros = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == 0) zeros++;
                if (zeros <= k) maxLen = Math.max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N²), Space: O(1)
    public int longestOnesTwoPointerShrink(int[] nums, int k) {
        int n = nums.length, maxLen = 0;
        for (int i = 0; i < n; i++) {
            int zeros = 0, j = i;
            while (j < n) {
                if (nums[j] == 0) zeros++;
                if (zeros <= k) {
                    maxLen = Math.max(maxLen, j - i + 1);
                    j++;
                } else break;
            }
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N), Space: O(1)
    public int longestOnesSlidingWindow(int[] nums, int k) {
        int left = 0, zeros = 0, maxLen = 0;
        for (int right = 0; right < nums.length; right++) {
            if (nums[right] == 0) zeros++;
            while (zeros > k) {
                if (nums[left] == 0) zeros--;
                left++;
            }
            maxLen = Math.max(maxLen, right - left + 1);
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N), Space: O(1)
    public int longestOnesSlidingWindowOptimized(int[] nums, int k) {
        int left = 0, zeros = 0;
        for (int right = 0; right < nums.length; right++) {
            if (nums[right] == 0) zeros++;
            if (zeros > k) {
                if (nums[left] == 0) zeros--;
                left++;
            }
        }
        return nums.length - left;
    }
}
