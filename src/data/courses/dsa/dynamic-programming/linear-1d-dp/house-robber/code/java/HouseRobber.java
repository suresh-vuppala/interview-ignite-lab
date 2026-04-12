class Solution {
    public int rob(int[] nums) {
        if (nums.length == 1) return nums[0];
        int a = nums[0], b = Math.max(nums[0], nums[1]);
        for (int i = 2; i < nums.length; i++) { int c = Math.max(b, a+nums[i]); a=b; b=c; }
        return b;
    }
}