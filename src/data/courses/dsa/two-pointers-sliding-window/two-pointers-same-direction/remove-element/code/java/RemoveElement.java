// ============================================================
// Remove Element
// ============================================================

// ============================================================
// Solution 1: Fast/Slow — Copy Non-Val Forward
// Time: O(N) | Space: O(1)
// ============================================================
class Solution1 {
    public int removeElement(int[] nums, int val) {
        int j = 0;
        for (int num : nums) {
            if (num != val) nums[j++] = num;
        }
        return j;
    }
}

// ============================================================
// Solution 2: Swap with End — Fewer Writes
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
    public int removeElement(int[] nums, int val) {
        int n = nums.length, i = 0;

        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[--n]; // Swap with end, shrink
            } else {
                i++;
            }
        }

        return n;
    }
}
