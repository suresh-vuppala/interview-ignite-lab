// ============================================================
// Longest Consecutive Sequence
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Sort + Linear Scan
// Time: O(N log N) | Space: O(1)
// ============================================================
class Solution1 {
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) return 0;

        Arrays.sort(nums);
        int max = 1, cur = 1;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i - 1]) continue;
            if (nums[i] == nums[i - 1] + 1) cur++;
            else cur = 1;
            max = Math.max(max, cur);
        }

        return max;
    }
}

// ============================================================
// Solution 2: Hash Set — Count from Beginnings (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int n : nums) set.add(n);

        int maxLen = 0;
        for (int num : set) {
            // Only count from sequence beginnings
            if (!set.contains(num - 1)) {
                int cur = num, len = 1;
                while (set.contains(cur + 1)) { cur++; len++; }
                maxLen = Math.max(maxLen, len);
            }
        }

        return maxLen;
    }
}
