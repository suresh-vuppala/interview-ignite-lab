class Solution {
public:
    // Optimal: O(n) time, O(n) space — HashSet tracks seen elements
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) return true; // Already seen = duplicate
            seen.insert(num);
        }
        return false;
    }
};