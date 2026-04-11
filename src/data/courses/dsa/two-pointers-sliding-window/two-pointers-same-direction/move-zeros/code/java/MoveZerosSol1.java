class Solution {
    public void moveZeroes(int[] nums) {
        int j = 0;
        for (int n : nums) if (n != 0) nums[j++] = n;
        while (j < nums.length) nums[j++] = 0;
    }
}