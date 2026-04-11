class Solution {
public:
    // Optimal: O(n) time, O(1) extra space — Two passes with running variable
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        int leftProduct = 1;
        for (int i = 0; i < n; i++) {       // Pass 1: left products
            result[i] = leftProduct;
            leftProduct *= nums[i];
        }
        int rightProduct = 1;
        for (int i = n-1; i >= 0; i--) {    // Pass 2: multiply by right products
            result[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        return result;
    }
};