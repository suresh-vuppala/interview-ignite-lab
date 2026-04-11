class Solution {
    // Optimal: O(1) space — Slow/fast pointers
    public int removeDuplicates(int[] nums) {
        int j = 0;
        for (int i = 1; i < nums.length; i++)
            if (nums[i] != nums[j]) nums[++j] = nums[i];
        return j + 1;
    }
}