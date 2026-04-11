// ============================================================
// Contains Duplicate
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Brute Force — Check All Pairs
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
    public boolean containsDuplicate(int[] nums) {

        // Compare every pair (i, j)
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] == nums[j]) return true;
            }
        }

        return false;
    }
}

// ============================================================
// Solution 2: Sort + Adjacent Check
// Time: O(N log N) | Space: O(1)
// ============================================================
class Solution2 {
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i - 1]) return true;
        }

        return false;
    }
}

// ============================================================
// Solution 3: Hash Set — O(1) Lookup (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution3 {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> seen = new HashSet<>();

        for (int num : nums) {
            if (!seen.add(num)) return true; // add returns false if already exists
        }

        return false;
    }
}
