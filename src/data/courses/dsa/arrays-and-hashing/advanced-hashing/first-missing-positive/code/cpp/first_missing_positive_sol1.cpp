class Solution {
public:
    // Hash Set: O(n) time, O(n) space
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        for (int i = 1; i <= nums.size() + 1; i++) {
            if (!numSet.count(i)) return i;  // First missing
        }
        return nums.size() + 1;
    }
};