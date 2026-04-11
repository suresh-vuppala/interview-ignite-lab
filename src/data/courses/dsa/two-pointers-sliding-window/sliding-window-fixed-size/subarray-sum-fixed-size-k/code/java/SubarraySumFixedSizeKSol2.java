class Solution {
    public boolean hasSubarraySum(int[] nums, int k, int target) {
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (i >= k) sum -= nums[i - k];
            if (i >= k - 1 && sum == target) return true;
        }
        return false;
    }
}