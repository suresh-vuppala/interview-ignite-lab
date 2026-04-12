class Solution {
    public int rob(int[] nums) {
        if (nums.length == 1) return nums[0];
        return Math.max(robRange(nums,0,nums.length-2), robRange(nums,1,nums.length-1));
    }
    int robRange(int[] nums, int lo, int hi) {
        int a=0, b=0;
        for (int i=lo; i<=hi; i++) { int c=Math.max(b, a+nums[i]); a=b; b=c; }
        return b;
    }
}