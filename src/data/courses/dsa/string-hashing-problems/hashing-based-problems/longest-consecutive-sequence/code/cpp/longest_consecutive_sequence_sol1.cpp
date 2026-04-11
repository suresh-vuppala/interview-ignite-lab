class Solution {
public:
    // Sort: O(n log n) — Sort then scan consecutive runs
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int maxLen = 1, curLen = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) continue;       // Skip duplicates
            if (nums[i] == nums[i-1] + 1) curLen++;   // Extend streak
            else curLen = 1;                            // Reset
            maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }
};