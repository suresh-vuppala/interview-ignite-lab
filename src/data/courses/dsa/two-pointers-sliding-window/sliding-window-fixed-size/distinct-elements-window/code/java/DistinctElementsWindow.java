// ============================================================
// Distinct Elements in Every Window of Size K
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Brute Force — Set per Window
// Time: O(N×K) | Space: O(K)
// ============================================================
class Solution1 {
    public int[] distinctInWindow(int[] nums, int k) {
        int[] result = new int[nums.length - k + 1];
        for (int i = 0; i <= nums.length - k; i++) {
            Set<Integer> s = new HashSet<>();
            for (int j = i; j < i + k; j++) s.add(nums[j]);
            result[i] = s.size();
        }
        return result;
    }
}

// ============================================================
// Solution 2: Sliding Window + Frequency Map (Optimal)
// Time: O(N) | Space: O(K)
// ============================================================
class Solution2 {
    public int[] distinctInWindow(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        int[] result = new int[nums.length - k + 1];
        int idx = 0;

        for (int i = 0; i < nums.length; i++) {
            freq.merge(nums[i], 1, Integer::sum);

            if (i >= k) {
                freq.merge(nums[i - k], -1, Integer::sum);
                if (freq.get(nums[i - k]) == 0) freq.remove(nums[i - k]);
            }

            if (i >= k - 1) result[idx++] = freq.size();
        }

        return result;
    }
}
