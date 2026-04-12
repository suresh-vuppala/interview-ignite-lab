class Solution {
public:
    // Brute Force O(N²)
    int maxSubArrayBrute(vector<int>& nums) {
        int maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j]; maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }

    // Kadane's O(N)
    int maxSubArray(vector<int>& nums) {
        int currSum = nums[0], maxSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            currSum = max(nums[i], currSum + nums[i]); // Extend or start new
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
