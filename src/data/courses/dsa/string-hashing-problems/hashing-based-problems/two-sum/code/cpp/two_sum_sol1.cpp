class Solution {
public:
    // Brute Force: O(n²) time, O(1) space — Check every pair
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {          // Fix first element
            for (int j = i + 1; j < n; j++) {       // Check all elements after it
                if (nums[i] + nums[j] == target) {  // Found the pair
                    return {i, j};
                }
            }
        }
        return {}; // No solution (shouldn't happen per constraints)
    }
};