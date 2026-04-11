class Solution {
public:
    // O(n) time, O(1) space — Index marking: negate value at index nums[i]-1
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1; // Map value to index
            if (nums[idx] < 0) {
                // Already visited → this value is a duplicate
                result.push_back(idx + 1);
            } else {
                nums[idx] = -nums[idx]; // Mark as visited by negating
            }
        }
        return result;
    }
};