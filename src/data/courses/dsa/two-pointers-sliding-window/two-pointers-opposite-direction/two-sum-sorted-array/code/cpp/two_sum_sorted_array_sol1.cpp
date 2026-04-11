class Solution {
public:
    // Brute Force: O(n²) — Check all pairs
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++)
            for (int j = i+1; j < nums.size(); j++)
                if (nums[i] + nums[j] == target) return {i+1, j+1};
        return {};
    }
};