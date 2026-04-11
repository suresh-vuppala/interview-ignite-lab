import java.util.*;

public class TwoSum {

    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(N²) | Space: O(1)
    // Check every pair of elements for the target sum
    public int[] twoSumBrute(int[] nums, int target) {
        // Try all pairs (i, j) where i < j
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                // Check if this pair sums to target
                if (nums[i] + nums[j] == target) {
                    return new int[]{i, j};
                }
            }
        }
        return new int[]{};
    }

    // ==================== SOLUTION 2: HASH MAP — ONE PASS ====================
    // Time: O(N) | Space: O(N)
    // Store seen numbers in map, look up complement in O(1)
    public int[] twoSumHashMap(int[] nums, int target) {
        Map<Integer, Integer> seen = new HashMap<>(); // value -> index

        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];

            // Check if complement was already seen
            if (seen.containsKey(complement)) {
                return new int[]{seen.get(complement), i};
            }

            // Store current number for future lookups
            seen.put(nums[i], i);
        }

        return new int[]{};
    }

    // Main solution - recommended approach
    public int[] twoSum(int[] nums, int target) {
        return twoSumHashMap(nums, target);
    }
}
