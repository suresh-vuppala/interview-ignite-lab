class Solution {
public:
    // Optimal: O(1) space — Slow/fast two pointers
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int j = 0; // j = last unique position
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[j]) {   // Found new unique value
                j++;
                nums[j] = nums[i];      // Write to next position
            }
        }
        return j + 1;
    }
};