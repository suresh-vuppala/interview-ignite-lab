class Solution {
public:
    // O(n) time, O(n) space — Hash map stores complement lookups
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // value -> index
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            // Check if complement was seen before
            if (mp.count(complement)) {
                return {mp[complement], i};
            }
            mp[nums[i]] = i; // Store current number's index
        }
        return {}; // No solution found (shouldn't happen per constraints)
    }
};