class SquaresSortedArray {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        int l = 0, r = n - 1, k = n - 1;
        while (l <= r) {
            if (Math.abs(nums[l]) > Math.abs(nums[r])) {
                res[k--] = nums[l] * nums[l];
                l++;
            } else {
                res[k--] = nums[r] * nums[r];
                r--;
            }
        }
        return res;
    }
}