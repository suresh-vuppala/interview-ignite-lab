// ============================================================
// First Missing Positive
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Hash Set
// Time: O(N) | Space: O(N)
// ============================================================
class Solution1 {
    public int firstMissingPositive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int n : nums) set.add(n);

        for (int i = 1; i <= nums.length + 1; i++) {
            if (!set.contains(i)) return i;
        }

        return nums.length + 1;
    }
}

// ============================================================
// Solution 2: Cyclic Sort — Array as Hash Map (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;

        // Cyclic sort: place value v at index v-1
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                int t = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = t;
            }
        }

        // Find first mismatch
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) return i + 1;
        }

        return n + 1;
    }
}
