// ============================================================
// Max Sum Subarray Not Greater Than M
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Brute Force
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
    public int maxSumNotGreater(int[] nums, int M) {
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            int sum = 0;
            for (int j = i; j < nums.length; j++) {
                sum += nums[j];
                if (sum <= M) max = Math.max(max, sum);
            }
        }
        return max;
    }
}

// ============================================================
// Solution 2: Prefix Sum + TreeSet (Optimal)
// Time: O(N log N) | Space: O(N)
// ============================================================
class Solution2 {
    public int maxSumNotGreater(int[] nums, int M) {
        TreeSet<Long> set = new TreeSet<>();
        set.add(0L);

        long prefix = 0, max = Long.MIN_VALUE;

        for (int num : nums) {
            prefix += num;

            // Find smallest prefix ≥ (prefix - M)
            Long ceiling = set.ceiling(prefix - M);

            if (ceiling != null) {
                max = Math.max(max, prefix - ceiling);
            }

            set.add(prefix);
        }

        return (int) max;
    }
}
