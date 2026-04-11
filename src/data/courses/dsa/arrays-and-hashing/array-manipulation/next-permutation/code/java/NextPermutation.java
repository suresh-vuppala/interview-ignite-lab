// ============================================================
// Next Permutation
// ============================================================

// ============================================================
// Solution: Three-Step Algorithm (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length, i = n - 2;

        // Step 1: Find rightmost dip
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;

        if (i >= 0) {
            // Step 2: Find rightmost element > nums[i]
            int j = n - 1;
            while (nums[j] <= nums[i]) j--;

            // Step 3: Swap
            int temp = nums[i]; nums[i] = nums[j]; nums[j] = temp;
        }

        // Step 4: Reverse suffix
        int l = i + 1, r = n - 1;
        while (l < r) {
            int temp = nums[l]; nums[l] = nums[r]; nums[r] = temp;
            l++; r--;
        }
    }
}
