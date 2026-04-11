// ============================================================
// Squares of a Sorted Array
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Square + Sort
// Time: O(N log N) | Space: O(1)
// ============================================================
class Solution1 {
    public int[] sortedSquares(int[] nums) {
        for (int i = 0; i < nums.length; i++) nums[i] *= nums[i];
        Arrays.sort(nums);
        return nums;
    }
}

// ============================================================
// Solution 2: Two Pointers from Ends (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        int left = 0, right = n - 1, pos = n - 1;

        while (left <= right) {
            int lSq = nums[left] * nums[left];
            int rSq = nums[right] * nums[right];

            if (lSq > rSq) {
                result[pos] = lSq;
                left++;
            } else {
                result[pos] = rSq;
                right--;
            }
            pos--;
        }

        return result;
    }
}
