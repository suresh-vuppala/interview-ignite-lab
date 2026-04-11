class Solution {
public:
    // Sort + Scan: O(n log n) — Duplicates become adjacent after sorting
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) return true; // Adjacent match = duplicate
        }
        return false;
    }
};