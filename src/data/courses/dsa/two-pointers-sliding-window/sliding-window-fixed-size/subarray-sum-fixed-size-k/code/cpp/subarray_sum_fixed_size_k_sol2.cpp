class Solution {
public:
    // Optimal: O(n) — Slide window, add/subtract at edges
    bool hasSubarraySum(vector<int>& nums, int k, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];                    // Add entering element
            if (i >= k) sum -= nums[i - k];    // Remove leaving element
            if (i >= k - 1 && sum == target) return true;
        }
        return false;
    }
};