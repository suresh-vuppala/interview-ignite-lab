class Solution {
public:
    // Optimal: O(n) time, O(n) space — Hash map for complement lookup
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // value -> index
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (seen.count(complement)) {       // Complement already seen?
                return {seen[complement], i};   // Return both indices
            }
            seen[nums[i]] = i;                  // Store current for future lookups
        }
        return {};
    }
};