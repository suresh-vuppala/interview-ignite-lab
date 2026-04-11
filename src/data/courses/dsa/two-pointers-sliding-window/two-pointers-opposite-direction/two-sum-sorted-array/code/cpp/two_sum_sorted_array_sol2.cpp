class Solution {
public:
    // Optimal: O(n) — Two pointers from ends
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) return {left + 1, right + 1};
            if (sum < target) left++;    // Need larger sum
            else right--;                // Need smaller sum
        }
        return {};
    }
};