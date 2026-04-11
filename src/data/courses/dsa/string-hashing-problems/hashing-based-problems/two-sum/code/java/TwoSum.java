// ============================================================
// Two Sum
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Brute Force
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
    public int[] twoSum(int[] nums, int target) {

        // Try every possible pair (i, j) where i < j
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++) {

                // Check if this pair sums to target
                if (nums[i] + nums[j] == target) {
                    return new int[]{i, j};
                }
            }
        }

        return new int[]{}; // No solution found
    }
}

// ============================================================
// Solution 2: Hash Map — One Pass (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
    public int[] twoSum(int[] nums, int target) {
        // Map stores: value → index (for O(1) complement lookup)
        Map<Integer, Integer> seen = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            // For current number, compute what we need
            int complement = target - nums[i];

            // Check if complement was seen earlier
            if (seen.containsKey(complement)) {
                return new int[]{seen.get(complement), i}; // Found!
            }

            // Store current number for future lookups
            seen.put(nums[i], i);
        }

        return new int[]{};
    }
}
