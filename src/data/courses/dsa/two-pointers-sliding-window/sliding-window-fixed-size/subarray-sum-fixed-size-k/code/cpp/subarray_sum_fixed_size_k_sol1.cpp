class Solution {
public:
    // Brute: O(n×k) — Sum k elements for each window
    bool hasSubarraySum(vector<int>& nums, int k, int target) {
        for (int i = 0; i <= (int)nums.size() - k; i++) {
            int sum = 0;
            for (int j = i; j < i + k; j++) sum += nums[j]; // Sum entire window
            if (sum == target) return true;
        }
        return false;
    }
};