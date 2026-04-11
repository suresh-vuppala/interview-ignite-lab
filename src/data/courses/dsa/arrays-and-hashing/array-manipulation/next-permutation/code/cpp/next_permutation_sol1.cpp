class Solution {
public:
    // O(n) time, O(1) space — Find dip, swap, reverse suffix
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n - 2;
        // Step 1: Find rightmost ascending pair (the "dip")
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        if (i >= 0) {
            // Step 2: Find rightmost element > nums[i]
            int j = n - 1;
            while (nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);  // Step 3: Swap
        }
        // Step 4: Reverse suffix to get smallest arrangement
        reverse(nums.begin() + i + 1, nums.end());
    }
};