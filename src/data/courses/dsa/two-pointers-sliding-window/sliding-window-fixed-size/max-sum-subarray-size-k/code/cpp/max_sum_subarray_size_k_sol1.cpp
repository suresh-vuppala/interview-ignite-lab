class Solution {
public:
    int maxSumSubarray(vector<int>& nums, int k) {
        int maxSum = INT_MIN;
        for (int i = 0; i <= (int)nums.size()-k; i++) {
            int sum = 0;
            for (int j = i; j < i+k; j++) sum += nums[j];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};