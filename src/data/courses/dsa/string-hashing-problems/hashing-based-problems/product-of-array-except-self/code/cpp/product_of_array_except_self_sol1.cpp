class Solution {
public:
    // Brute Force: O(n²) — For each element, multiply all others
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) result[i] *= nums[j]; // Skip self
            }
        }
        return result;
    }
};