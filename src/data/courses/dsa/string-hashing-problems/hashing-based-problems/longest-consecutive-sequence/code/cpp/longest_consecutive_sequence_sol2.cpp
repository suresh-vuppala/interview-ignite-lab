class Solution {
public:
    // Optimal: O(n) — Only count from sequence beginnings
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLen = 0;
        for (int num : numSet) {
            // Only start if this is a sequence BEGINNING
            if (!numSet.count(num - 1)) {
                int cur = num, len = 1;
                while (numSet.count(cur + 1)) { cur++; len++; }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};