class Solution {
public:
    // Optimal: Single pass — swap non-zeros to front
    void moveZeroes(vector<int>& nums) {
        int j = 0; // Next position for non-zero
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]); // Swap non-zero to front
                j++;
            }
        }
    }
};