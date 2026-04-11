class Solution {
    public boolean hasSubarraySum(int[] nums, int k, int target) {
        for (int i = 0; i <= nums.length - k; i++) {
            int sum = 0;
            for (int j = i; j < i + k; j++) sum += nums[j];
            if (sum == target) return true;
        }
        return false;
    }
}