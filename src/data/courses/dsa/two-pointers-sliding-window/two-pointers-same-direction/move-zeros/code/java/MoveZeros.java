// ============================================================
// Move Zeroes
// ============================================================

// ============================================================
// Solution 1: Two-Pass (Copy then Fill)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution1 {
    public void moveZeroes(int[] nums) {
        int j = 0;
        for (int n : nums) if (n != 0) nums[j++] = n;
        while (j < nums.length) nums[j++] = 0;
    }
}

// ============================================================
// Solution 2: Single-Pass Swap (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
    public void moveZeroes(int[] nums) {
        int j = 0;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j++;
            }
        }
    }
}
