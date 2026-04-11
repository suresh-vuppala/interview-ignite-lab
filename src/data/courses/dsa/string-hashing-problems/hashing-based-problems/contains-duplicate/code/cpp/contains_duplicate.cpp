class Solution {
public:
    // O(n) time, O(n) space — HashSet tracks seen elements
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            // If already in set, we found a duplicate
            if (seen.count(num)) return true;
            seen.insert(num);
        }
        return false; // All elements are unique
    }
};