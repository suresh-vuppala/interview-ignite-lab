class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length, l = 0, r = n-1, pos = n-1;
        int[] res = new int[n];
        while (l <= r) {
            if (Math.abs(nums[l]) > Math.abs(nums[r])) { res[pos--] = nums[l]*nums[l]; l++; }
            else { res[pos--] = nums[r]*nums[r]; r--; }
        }
        return res;
    }
}