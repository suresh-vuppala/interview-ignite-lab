// ============================================================
// Remove Duplicates from Sorted Array
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Extra Array
// Time: O(N) | Space: O(N)
// ============================================================
class Solution1 {
    public int removeDuplicates(int[] nums) {
        List<Integer> unique = new ArrayList<>();
        unique.add(nums[0]);

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != unique.get(unique.size() - 1)) {
                unique.add(nums[i]);
            }
        }

        for (int i = 0; i < unique.size(); i++) nums[i] = unique.get(i);
        return unique.size();
    }
}

// ============================================================
// Solution 2: Slow/Fast Two Pointers (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
    public int removeDuplicates(int[] nums) {
        int j = 0;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[j]) {
                j++;
                nums[j] = nums[i];
            }
        }

        return j + 1;
    }
}
