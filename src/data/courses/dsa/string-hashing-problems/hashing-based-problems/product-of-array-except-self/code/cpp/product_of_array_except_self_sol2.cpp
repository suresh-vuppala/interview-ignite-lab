class Solution {
public:
    // Prefix + Suffix: O(n) time, O(n) space
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1), suffix(n, 1), result(n);
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i-1] * nums[i-1];    // Left products
        for (int i = n-2; i >= 0; i--)
            suffix[i] = suffix[i+1] * nums[i+1];    // Right products
        for (int i = 0; i < n; i++)
            result[i] = prefix[i] * suffix[i];       // Combine
        return result;
    }
};