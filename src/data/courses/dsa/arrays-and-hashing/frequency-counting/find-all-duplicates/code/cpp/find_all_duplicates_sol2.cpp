class Solution {
public:
    // Optimal: O(n) time, O(1) space — Negate at index to mark visited
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;     // Map value to 0-indexed position
            if (nums[idx] < 0)              // Already visited → duplicate
                result.push_back(idx + 1);
            else
                nums[idx] = -nums[idx];     // Mark visited by negating
        }
        return result;
    }
};