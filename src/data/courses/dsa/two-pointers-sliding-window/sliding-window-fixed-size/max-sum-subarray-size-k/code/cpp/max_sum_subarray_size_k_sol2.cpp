class Solution {
public:
    int maxSumSubarray(vector<int>& nums, int k) {
        int sum = 0, maxSum;
        for (int i = 0; i < k; i++) sum += nums[i]; // First window
        maxSum = sum;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i-k]; // Slide: add right, remove left
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};