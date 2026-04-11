class Solution {
public:
    // O(n) time, O(n) space — HashSet + only start from sequence beginnings
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLen = 0;
        
        for (int num : numSet) {
            // Only start counting if num is the START of a sequence
            // (i.e., num-1 is NOT in the set)
            if (!numSet.count(num - 1)) {
                int currentNum = num;
                int currentLen = 1;
                
                // Count consecutive numbers
                while (numSet.count(currentNum + 1)) {
                    currentNum++;
                    currentLen++;
                }
                maxLen = max(maxLen, currentLen);
            }
        }
        return maxLen;
    }
};