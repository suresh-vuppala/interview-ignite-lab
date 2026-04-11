class Solution {
public:
    // Two-Pass: Copy non-zeros forward, fill rest with zeros
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        // Pass 1: Copy all non-zeros to front
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) nums[j++] = nums[i];
        }
        // Pass 2: Fill remaining positions with zeros
        while (j < nums.size()) nums[j++] = 0;
    }
};