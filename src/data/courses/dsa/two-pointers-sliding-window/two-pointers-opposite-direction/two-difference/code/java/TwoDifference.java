// ============================================================
// Two Difference
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Brute Force — All Pairs
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
    public boolean findPair(int[] nums, int k) {
        for (int i = 0; i < nums.length; i++)
            for (int j = i + 1; j < nums.length; j++)
                if (Math.abs(nums[i] - nums[j]) == k) return true;
        return false;
    }
}

// ============================================================
// Solution 2: Sort + Two Pointers (Optimal)
// Time: O(N log N) | Space: O(1)
// ============================================================
class Solution2 {
    public boolean findPair(int[] nums, int k) {
        Arrays.sort(nums);
        int i = 0, j = 1;

        while (i < nums.length && j < nums.length) {
            if (i == j) { j++; continue; }
            int diff = nums[j] - nums[i];
            if (diff == k) return true;
            if (diff < k) j++;
            else i++;
        }

        return false;
    }
}
