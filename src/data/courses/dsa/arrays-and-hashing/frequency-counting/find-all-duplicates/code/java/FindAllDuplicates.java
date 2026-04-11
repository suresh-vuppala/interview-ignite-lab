// ============================================================
// Find All Duplicates in Array
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Hash Set
// Time: O(N) | Space: O(N)
// ============================================================
class Solution1 {
    public List<Integer> findDuplicates(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        List<Integer> result = new ArrayList<>();

        for (int num : nums) {
            if (!seen.add(num)) result.add(num);
        }

        return result;
    }
}

// ============================================================
// Solution 2: Index Marking — Negate to Flag (Optimal)
// Time: O(N) | Space: O(1) extra
// ============================================================
class Solution2 {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> result = new ArrayList<>();

        for (int num : nums) {
            int idx = Math.abs(num) - 1;

            if (nums[idx] < 0) {
                result.add(idx + 1);  // Duplicate found
            } else {
                nums[idx] = -nums[idx]; // Mark visited
            }
        }

        return result;
    }
}
