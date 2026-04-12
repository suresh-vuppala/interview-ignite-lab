class Solution {
    public int maxSumNonAdjacent(int[] nums) {
        if (nums.length == 0) return 0;
        int a = Math.max(0, nums[0]), b = nums.length > 1 ? Math.max(a, nums[1]) : a;
        for (int i = 2; i < nums.length; i++) { int c = Math.max(b, a+nums[i]); a=b; b=c; }
        return b;
    }
}